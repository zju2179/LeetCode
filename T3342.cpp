#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

// myx modify
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

#include "/data/backtrack/arcanum/chromium/src/base/strings/stringprintf.h"
#include "/data/backtrack/arcanum/chromium/src/v8/include/v8-message.h"
// #include "/data/backtrack/arcanum/chromium/src/v8/src/api/api.cc"
#include "/data/backtrack/arcanum/chromium/src/v8/src/execution/isolate.h"
#include "src/api/api-inl.h"
#include "src/api/api-macros.h"
#include "src/api/api.h"
#include "src/execution/isolate.h"
// myx modify

using namespace std;

const int N = 100;
bool st[N][N];
int dist[N][N];
const int INF = 1e9 + 7;
int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
class Solution
{
public:
    bool isValid(int x, int y)
    {
        if (x >= 0 && x < n && y >= 0 && y < m)
            return true;
        return false;
    }
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        fill(dist[0], dist[0] + N * N, INF);
        dist[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        n = moveTime.size();
        m = moveTime[0].size();
        pq.push({0, 0, 0}); // {d, x, y}

        while (true)
        {
            auto [d, x, y] = pq.top();
            pq.pop();
            if (x == n - 1 && y == m - 1)
                return d;
            for (int i = 0; i < 4; i++)
            {
                int nextX = x + dx[i], nextY = y + dy[i];
                if (isValid(nextX, nextY))
                {
                    int new_dis = max(moveTime[nextX][nextY], dist[x][y]) + (x + y) % 2 + 1;
                    if (new_dis < dist[nextX][nextY])
                        dist[nextX][nextY] = new_dis;
                    pq.push({dist[nextX][nextY], nextX, nextY});
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
int main()
{
    Solution s;
    vector<vector<int>> moveTime = {{0, 4}, {4, 4}};
    cout << s.minTimeToReach(moveTime) << endl;
    // myx modify
    // ENTER_V8_NO_SCRIPT_NO_EXCEPTION(isolate);
    // isolate->PrintCurrentStackTrace(std::cout);

    // FILE* stackTraceFile =
    //     fopen("/data/backtrack/arcanum/test_JavaScript/stack_trace.txt", "a");
    // if (stackTraceFile == nullptr) {
    //   std::cerr << "Failed to open stack_trace.txt for writing." << std::endl;
    // } else {
    //   const char* test_trigger = "SetProperty() is triggered\n";
    //   fputs(test_trigger, stackTraceFile);
    //   ENTER_V8_NO_SCRIPT_NO_EXCEPTION(isolate);
    //   i::DirectHandle<i::StackTraceInfo> stack_trace =
    //       isolate->CaptureDetailedStackTrace(10);
    //   v8::Local<v8::StackTrace> stack_trace =
    //       Utils::StackTraceToLocal(stack_trace);
    //   if (stack_trace.IsEmpty() || stack_trace->GetFrameCount() == 0) {
    //     std::cerr << "<no stack trace>" << std::endl;
    //   }
    //   std::string result;
    //   for (int i = 0; i < stack_trace->GetFrameCount(); ++i) {
    //     v8::Isolate* isolate_ = reinterpret_cast<v8::Isolate*>(isolate);
    //     v8::Local<v8::StackFrame> frame = stack_trace->GetFrame(isolate_, i);
    //     if (frame.IsEmpty()) break;
    //     result += base::StringPrintf(
    //         "\n    at %s (%s:%d:%d)",
    //         ToStringOrDefault(isolate, frame->GetFunctionName(), "<anonymous>")
    //             .c_str(),
    //         ToStringOrDefault(isolate, frame->GetScriptName(), "<anonymous>")
    //             .c_str(),
    //         frame->GetLineNumber(), frame->GetColumn());
    //   }
    //   fputs(result, stackTraceFile);
    //   // ENTER_V8_NO_SCRIPT_NO_EXCEPTION(isolate);
    //   // isolate->PrintCurrentStackTrace(stackTraceFile);
    //   fclose(stackTraceFile);
    // }

    // myx modify

    // ENTER_V8_NO_SCRIPT_NO_EXCEPTION(isolate);
        // i::DirectHandle<i::StackTraceInfo> stack_trace =
    //     isolate->CaptureDetailedStackTrace(10);
    // v8::Local<v8::StackTrace> stack_trace =
    //     Utils::StackTraceToLocal(stack_trace);
        v8::Isolate *cur_isolate_ = reinterpret_cast<v8::Isolate *>(isolate);
    v8::Local<v8::StackTrace> stack_trace =
        v8::StackTrace::CurrentStackTrace(cur_isolate_, 10);
    if (stack_trace.IsEmpty() || stack_trace->GetFrameCount() == 0)
    {
        std::cerr << "<no stack trace>" << std::endl;
    }
    std::string result;
    // raw_ptr<v8::Isolate>
    for (int i = 0; i < stack_trace->GetFrameCount(); ++i)
    {
        v8::Local<v8::StackFrame> frame = stack_trace->GetFrame(cur_isolate_, i);
        if (frame.IsEmpty())
            break;
        result += ::base::StringPrintf(
            "\n   at %s (%s:%d:%d)",
            ToStringOrDefault_(cur_isolate_, frame->GetFunctionName(),
                               "<anonymous>")
                .c_str(),
            ToStringOrDefault_(cur_isolate_, frame->GetScriptName(),
                               "<anonymous>")
                .c_str(),
            frame->GetLineNumber(), frame->GetColumn());
    }
    fputs(result.c_str(), stackTraceFile);
    return 0;
}