#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    int n = position.size();
    int res = 0;
    vector<double> time(target + 1, 0);
    for (int i = 0; i < n; i++)
        time[position[i]] = (double)(target - position[i]) / (double)speed[i];
    stack<double> s; // 单调递增栈，从底到顶单调递增
    for (int p = 0; p < target; p++)
    {
        if (time[p] > 0)
        {
            while (!s.empty() && time[p] >= s.top())
            {
                s.pop();
            }
            s.push(time[p]);
        }
    }
    res = s.size();
    return res;
}

int main()
{

    return 0;
}