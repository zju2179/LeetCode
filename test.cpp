
int frames_seen = 0;
for (StackTraceFrameIterator it(this); !it.done() && (frames_seen < limit);
     it.Advance())
{
  // StandardFrame* frame = it.frame();
  StackFrame *frame = it.frame();
  if (frame->is_java_script())
  { /* let's ignore Wasm frames for now */
    /* Set initial size to the maximum inlining level + 1 for the outermost
      function. */
    // List<FrameSummary> frames(FLAG_max_inlining_levels + 1);
    // JavaScriptFrame::cast(frame)->Summarize(&frames);
    std::vector<FrameSummary::JavaScriptFrameSummary> frames;
    JavaScriptFrame::cast(frame)->Summarize_myx(&frames);
    for (int i = static_cast<int>(frames.size()) - 1;
         i >= 0 && frames_seen < limit; i--)
    {
      Handle<JSFunction> fun = frames[i].function();
      /* Filter frames from other security contexts. */
      if (!(options & StackTrace::kExposeFramesAcrossSecurityOrigins) &&
          !this->context().HasSameSecurityTokenAs(fun->context()))
        continue;

      Handle<StackFrameInfo> frame_info = frames[i].CreateStackFrameInfo();
      // Handle<JSObject> new_frame_obj =
      // helper.NewStackFrameObject(frames[i]);

      stack_trace_elems->set(frames_seen, *frame_info);

      UnoptimizedCompilationInfo *info = this->GetCompilationInfo(fun);
      std::cout << "start JS call stack [" << frames_seen
                << "]: " << fun->shared().HasInferredName() << std::endl;
      BacktrackScopeDFG *dfg = this->GetBacktrackScopeDFG(
          info, info->scope()->start_position(),
          reinterpret_cast<void *>(JavaScriptFrame::cast(frame)->fp()));
      // std::cout << "logged isolate: " << dfg->isolate() << ", " <<
      // info->isolate() << std::endl;

      // myx modify
      call_stack.push_back(dfg); // zmx: in the reversed order
      // call_stack.push_back(std::make_unique<BacktrackScopeDFG>(*dfg));
      // v8::internal::GetCallStack().push_back(dfg);
      // myx modify
      if (dfg != nullptr)
      {
        // std::cout << "finished JS call stack [" << frames_seen << "]:
        "<<
        // fun->shared()->HasInferredName() << std::endl;
        // dfg->TrackBackDFG();
      }
      frames_seen++;
    }
  }
}

template <typename Visitor>
void VisitStack(Isolate *isolate, Visitor *visitor,
                StackTrace::StackTraceOptions options = StackTrace::kDetailed)
{
  DisallowJavascriptExecution no_js(isolate);
  for (StackFrameIterator it(isolate); !it.done(); it.Advance())
  {
    StackFrame *frame = it.frame();
    switch (frame->type())
    {
    case StackFrame::BUILTIN_EXIT:
    case StackFrame::JAVA_SCRIPT_BUILTIN_CONTINUATION:
    case StackFrame::JAVA_SCRIPT_BUILTIN_CONTINUATION_WITH_CATCH:
    case StackFrame::TURBOFAN:
    case StackFrame::MAGLEV:
    case StackFrame::INTERPRETED:
    case StackFrame::BASELINE:
    case StackFrame::BUILTIN:
#if V8_ENABLE_WEBASSEMBLY
    case StackFrame::WASM:
#endif // V8_ENABLE_WEBASSEMBLY
    {
      // A standard frame may include many summarized frames (due to
      // inlining).
      std::vector<FrameSummary> summaries;
      CommonFrame::cast(frame)->Summarize(&summaries);
      for (auto rit = summaries.rbegin(); rit != summaries.rend(); ++rit)
      {
        FrameSummary &summary = *rit;
        // Skip frames from other origins when asked to do so.
        if (!(options & StackTrace::kExposeFramesAcrossSecurityOrigins) &&
            !summary.native_context()->HasSameSecurityTokenAs(
                isolate->context()))
        {
          continue;
        }
        if (!visitor->Visit(summary))
          return;
      }
      break;
    }

    default:
      break;
    }
  }
}

Handle<FixedArray> CaptureSimpleStackTrace(Isolate *isolate, int limit,
                                           FrameSkipMode mode,
                                           Handle<Object> caller)
{
  TRACE_EVENT_BEGIN1(TRACE_DISABLED_BY_DEFAULT("v8.stack_trace"), __func__,
                     "maxFrameCount", limit);

#if V8_ENABLE_WEBASSEMBLY
  wasm::WasmCodeRefScope code_ref_scope;
#endif // V8_ENABLE_WEBASSEMBLY

  CallSiteBuilder builder(isolate, mode, limit, caller);
  VisitStack(isolate, &builder);

  // If --async-stack-traces are enabled and the "current microtask" is a
  // PromiseReactionJobTask, we try to enrich the stack trace with async
  // frames.
  if (v8_flags.async_stack_traces)
  {
    CaptureAsyncStackTrace(isolate, &builder);
  }

  Handle<FixedArray> stack_trace = builder.Build();
  TRACE_EVENT_END1(TRACE_DISABLED_BY_DEFAULT("v8.stack_trace"), __func__,
                   "frameCount", stack_trace->length());
  return stack_trace;
}