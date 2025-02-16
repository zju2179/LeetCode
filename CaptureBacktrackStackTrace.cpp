Handle<JSArray> Isolate::CaptureBacktrackStackTrace(
    int frame_limit, StackTrace::StackTraceOptions options) {
  DisallowJavascriptExecution no_js(this);
  // CaptureStackTraceHelper helper(this, options);

  /* Ensure no negative values. */
  int limit = std::max(frame_limit, 0);

  // myx add
  // Handle<FixedArray> frames_myx = CaptureSimpleStackTrace(
  //     this, FixedArray::kMaxLength, SKIP_NONE, factory()->undefined_value());
  // IncrementalStringBuilder builder(this);
  // std::cout << "myx stack trace length: " << frames_myx->length() <<
  // std::endl; for (int i = 0; i < frames_myx->length(); ++i) {
  //   Handle<CallSiteInfo> frame(CallSiteInfo::cast(frames_myx->get(i)), this);
  //   SerializeCallSiteInfo(this, frame, &builder);
  // }

  // Handle<String> stack_trace_myx = builder.Finish().ToHandleChecked();
  // std::cout << "myx stack trace test: " << stack_trace_myx << std::endl;

  // FILE* stackTraceFile =
  //     fopen("/data/backtrack/arcanum/test_JavaScript/stack_trace.txt", "w");
  // if (stackTraceFile == nullptr) {
  //   std::cerr << "Failed to open stack_trace.txt for writing." << std::endl;
  // } else {
  //   const char* test_trigger = "SetProperty() is triggered\n";
  //   fputs(test_trigger, stackTraceFile);
  //   ENTER_V8_NO_SCRIPT_NO_EXCEPTION(this);
  //   this->PrintCurrentStackTrace(stackTraceFile);
  //   fclose(stackTraceFile);
  // }
  // std::cout<<"Now in CaptureBacktrackStackTrace"<<std::endl;
  // for(int i = 0; i < stack_trace->length(); i++){
  //   Handle<CallSiteInfo> frame(CallSiteInfo::cast(stack_trace->get(i)),
  //   this);

  //   std::cout<<frame->GetFunctionDebugName(frame)->ToCString()<<"->";
  // }
  // std::cout<<std::endl;
  // myx add

  Handle<JSArray> stack_trace = factory()->NewJSArray(frame_limit);
  Handle<FixedArray> stack_trace_elems(
      FixedArray::cast(stack_trace->elements()), this);

  int frames_seen = 0;
  for (StackTraceFrameIterator it(this); !it.done() && (frames_seen < limit);
       it.Advance()) {
    // StandardFrame* frame = it.frame();
    StackFrame* frame = it.frame();
    if (frame->is_java_script()) { /* let's ignore Wasm frames for now */
      /* Set initial size to the maximum inlining level + 1 for the outermost
        function. */
      // // List<FrameSummary> frames(FLAG_max_inlining_levels + 1);
      // // JavaScriptFrame::cast(frame)->Summarize(&frames);
      std::vector<FrameSummary::JavaScriptFrameSummary> frames;
      JavaScriptFrame::cast(frame)->Summarize_myx(&frames);

      // yy trytry
      // Handle<FixedArray> frames = CaptureSimpleStackTrace(
      //                 this, FixedArray::kMaxLength, SKIP_NONE,
      //                 factory()->undefined_value());
      // for (int i = 0; i < frames->length();i++){
      //   FrameSummary::JavaScriptFrameSummary current_frame =
      //   FrameSummary::JavaScriptFrameSummary::cast(frames->get(i));
      //   Handle<JSFunction> fun = current_frame.function();
      // }
      // yy trytry
      std::cout << "single frame size: " << frames.size() << std::endl;
      for (int i = static_cast<int>(frames.size()) - 1;
           i >= 0 && frames_seen < limit; i--) {
        Handle<JSFunction> fun = frames[i].function();
        /* Filter frames from other security contexts. */
        if (!(options & StackTrace::kExposeFramesAcrossSecurityOrigins) &&
            !this->context().HasSameSecurityTokenAs(fun->context()))
          continue;
        Handle<StackFrameInfo> frame_info = frames[i].CreateStackFrameInfo();
        // Handle<JSObject> new_frame_obj =
        // helper.NewStackFrameObject(frames[i]);

        stack_trace_elems->set(frames_seen, *frame_info);

        // function_map test
        // std::cout << "sfi: " << reinterpret_cast<std::string>(fun->shared()) << std::endl;
        // Handle<String> func_name = JSFunction::GetName(this, fun);
        // auto meta_info = GetFromFunctionMap(func_name->ToCString().get());
        // std::cout << meta_info->fp << " "
        //           << meta_info->info << " "
        //           << meta_info->position << std::endl;

        UnoptimizedCompilationInfo* info = this->GetCompilationInfo(fun);
        std::cout << "start JS call stack [" << frames_seen
                  << "]: " << fun->shared().HasInferredName() << std::endl;
        std::cout << "(caller site)this function is: " << fun << std::endl;
        // myx add
        // Address func_addr = fun->address();
        // Address shared_info_addr = fun->shared().address();
        // std::cout << "Isolate::CaptureBacktrackStackTrace::func_addr = "
        //           << func_addr << std::endl;
        // std::cout << "Isolate::CaptureBacktrackStackTrace::shared_info_addr = "
        //           << shared_info_addr << std::endl;
        // std::cout << "Isolate::CaptureBacktrackStackTrace::func_name = "
        //           << fun->DebugNameCStr().get() << std::endl;
        // std::cout<<"function->Print() Start: "<<std::endl;  
        // fun->Print();
        // std::cout<<"function->Print() end" <<std::endl;
        // myx add
        BacktrackScopeDFG* dfg = this->GetBacktrackScopeDFG(
            info, info->scope()->start_position(),
            reinterpret_cast<void*>(JavaScriptFrame::cast(frame)->fp()));
        // std::cout << "logged isolate: " << dfg->isolate() << ", " <<
        // info->isolate() << std::endl;

        // myx modify
        // v8::internal::AddToCallStackIfNotExists(dfg);
        call_stack.push_back(dfg);  // zmx: in the reversed order
        std::cout << "add dfg of [" << fun << "] to call_stack, "
                  << "(in isolate.cc)length of call_stack is: " << call_stack.size() << std::endl;
        // call_stack.push_back(std::make_unique<BacktrackScopeDFG>(*dfg));
        // v8::internal::GetCallStack().push_back(dfg);
        // myx modify
        if (dfg != nullptr) {
          // std::cout << "finished JS call stack [" << frames_seen << "]:"<<
          // fun->shared()->HasInferredName() << std::endl;
          // dfg->TrackBackDFG();
        }
        frames_seen++;
      }
    }
  }
  stack_trace->set_length(Smi::FromInt(frames_seen));
  return stack_trace;
}