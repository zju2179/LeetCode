#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

int n, m, p; //  PM 数量, 最多同时执行的任务数, idea 数量
const int N = 3010;

class Idea
{
public:
    int pm;            //  提出PM
    int proposal_time; //  提出时间
    int priority;      //  优先级
    int exe_time;      //  执行时间
    int idx;           //  在原输入当中的下标
    int finish_time;   //  完成时间

    bool operator<(const Idea a) const //  判断 PM 最 后 完成的任务, 用于每个 PM 子堆的排序
    {
        if (this->priority != a.priority) //  优先级更低
            return this->priority < a.priority;
        else if (this->exe_time != a.exe_time) //  执行时间更长
            return this->exe_time > a.exe_time;
        else if (this->proposal_time != a.proposal_time) //  提出时间更晚
            return this->proposal_time > a.proposal_time;
        else //  不存在的情况，保证稳定性
            return -1;
    }

    bool operator>(const Idea a) const //  判断 Monkey 最 先 挑选的任务, 用于当前可选任务堆的排序
    {
        if (this->exe_time != a.exe_time) //  执行时间更短
            return this->exe_time > a.exe_time;
        else
            return this->pm > a.pm; //  PM 编号更小
    }
};

bool cmp_proposal(Idea a, Idea b)
{
    return a.proposal_time < b.proposal_time;
}

void printIdeas(vector<Idea> a)
{
    for (Idea x : a)
        cout << x.pm << " " << x.proposal_time << " " << x.priority << " " << x.exe_time << " " << x.finish_time << endl;
}

int main()
{
    Idea ideas[N];
    cin >> n >> m >> p;

    for (int i = 0; i < p; i++)
    {
        cin >> ideas[i].pm >> ideas[i].proposal_time >> ideas[i].priority >> ideas[i].exe_time;
        ideas[i].idx = i;
    }

    // //     输入例子：
    // 2 2 5
    // 1 1 1 2
    // 1 2 1 1
    // 1 3 2 2
    // 2 1 1 2
    // 2 3 5 5

    //     n = 2;
    //     m = 2;
    //     p = 5;
    //     ideas[0].pm = 1; ideas[0].proposal_time = 1; ideas[0].priority = 1; ideas[0].exe_time = 2; ideas[0].idx = 0;
    //     ideas[1].pm = 1; ideas[1].proposal_time = 2; ideas[1].priority = 1; ideas[1].exe_time = 1; ideas[1].idx = 1;
    //     ideas[2].pm = 1; ideas[2].proposal_time = 3; ideas[2].priority = 2; ideas[2].exe_time = 2; ideas[2].idx = 2;
    //     ideas[3].pm = 2; ideas[3].proposal_time = 1; ideas[3].priority = 1; ideas[3].exe_time = 2; ideas[3].idx = 3;
    //     ideas[4].pm = 2; ideas[4].proposal_time = 3; ideas[4].priority = 5; ideas[4].exe_time = 5; ideas[4].idx = 4;

    //  首先对所有的 idea 进行排序 -> 提出时间, 放在新的数组当中
    vector<Idea> sorted_ideas(ideas, ideas + p);
    sort(sorted_ideas.begin(), sorted_ideas.end(), cmp_proposal);
    printIdeas(sorted_ideas);

    //  优先队列 程序员 Monkeys, 初始化为 所有提出时间最小值
    //  代表了 在哪个时间点，该 monkey 是空闲的
    priority_queue<int, vector<int>, greater<int>> monkeys;
    for (int i = 0; i < m; i++)
        monkeys.push(sorted_ideas[0].proposal_time);

    //  为每一个 PM 维护一个当前时间点之下的最大优先级任务堆 (从 1 开始)
    vector<priority_queue<Idea, vector<Idea>>> pm_ideas(n + 1);

    //  维护一个当前可选的任务堆 最小堆
    // priority_queue<Idea, vector<Idea>, greater<Idea>> available_ideas;

    int already_finish = 0;
    int time_ptr = 0;
    while (already_finish < p)
    {

        //  0. 先把 sorted_ideas 当中 提出时间 <= monkey.top() 的任务全部放入 PM 任务堆
        while (time_ptr < p && sorted_ideas[time_ptr].proposal_time <= monkeys.top())
        {
            Idea cur = sorted_ideas[time_ptr];
            pm_ideas[cur.pm].push(cur);
            time_ptr++;
        }

        //  1. 判断当前是否 "所有 idea 未全部完成, 但所有的 PM 堆都为空"
        bool all_pm_empty = true;
        for (int i = 1; i <= n; i++)
        {
            if (!pm_ideas[i].empty())
            {
                all_pm_empty = false;
                break;
            }
        }

        //  1-1 如果所有 PM 堆都为空, 且所有 idea 未全部完成, 则所有的 monkey 的时间都调整为 下一个 idea 的提出时间
        if (all_pm_empty && already_finish < p)
        {
            for (int i = 0; i < m; i++)
            {
                monkeys.pop();
                monkeys.push(sorted_ideas[time_ptr].proposal_time);
            }
        }

        //  1-2 如果 PM 并没有 全空，继续安排任务
        priority_queue<Idea, vector<Idea>, greater<Idea>> available_ideas;
        for (int i = 1; i <= n; i++)
        {
            if (!pm_ideas[i].empty())
            {
                Idea cur = pm_ideas[i].top(); //  把每个队列第一个元素放在 available_ideas 当中
                available_ideas.push(cur);
            }
        }

        int cur_time = monkeys.top(); //  只有当前时间不变才可以连续安排任务，否则需要首先更新 available_ideas
        while (!available_ideas.empty() && available_ideas.top().proposal_time <= monkeys.top() && cur_time == monkeys.top())
        {
            Idea cur = available_ideas.top();
            int cur_idx = cur.idx;
            int cur_pm = cur.pm;

            //  记录当前任务的完成情况
            int cur_finish_time = monkeys.top() + cur.exe_time;
            ideas[cur_idx].finish_time = cur_finish_time;
            already_finish++;
            // cout << "cur_time: " << cur_time << "cur_proposal_time: " << cur.proposal_time << " cur_pm: " << cur_pm << " cur_idx: " << cur_idx << " cur_finish_time: " << cur_finish_time << endl;
            // ideas[cur_idx].pm << " " << ideas[cur_idx].proposal_time << " " << ideas[cur_idx].priority << " " << ideas[cur_idx].exe_time << endl;

            //  更新 monkeys 堆
            monkeys.pop();
            monkeys.push(cur_finish_time);

            //  更新 PM 堆, 如果 PM 弹出后还有任务, 则把下一个任务放入 available_ideas
            available_ideas.pop();
            pm_ideas[cur_pm].pop();
            if (!pm_ideas[cur_pm].empty())
            {
                Idea next = pm_ideas[cur_pm].top();
                available_ideas.push(next);
            }
        }
    }

    for (int i = 0; i < p; i++)
        cout << ideas[i].finish_time << endl;
}
// 64 位输出请用 printf("%lld")