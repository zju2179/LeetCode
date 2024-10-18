#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 3010;

class Idea
{
public:
    int pm;
    int proposal_time;
    int priority;
    int exe_time;
    int finish_time;

    bool operator<(const Idea a) const
    { // 大根堆
        if (this->priority != a.priority)
            return this->priority > a.priority;
        else if (this->exe_time != a.exe_time)
            return this->exe_time > a.exe_time;
        else if (this->proposal_time != a.proposal_time)
            return this->proposal_time > a.proposal_time;
        else
            return this->pm > a.pm;
    }

    bool operator>(const Idea a) const
    { // 小根堆
        if (this->exe_time != a.exe_time)
            return this->exe_time > a.exe_time;
        else
            return this->pm > a.pm;
    }
};

