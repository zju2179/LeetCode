#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

const int MOD = 1e9 + 7;

class Point
{
public:
    int val, idx;
    bool operator>(const Point &p) const
    {
        if (this->val != p.val)
            return this->val > p.val;
        else
        {
            if (this->idx >= p.idx)
                return true;
            else
                return false;
        }
    }
};

vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
{
    priority_queue<Point, vector<Point>, greater<Point>> pq;
    vector<int> res = nums;
    int n = nums.size();
    for (int i = 0; i < n; i++)
        pq.push({nums[i], i});
    while (k--)
    {
        Point p = pq.top();
        pq.pop();
        p.val = p.val * multiplier % MOD;
        pq.push(p);
    }
    while (!pq.empty())
    {
        Point p = pq.top();
        res[p.idx] = p.val;
        pq.pop();
    }
    return res;
}
int main()
{
    vector<int> nums = {2, 1, 3, 5, 6};
    int k = 5, multiplier = 2;
    vector<int> res = getFinalState(nums, k, multiplier);
    for (int x : res)
        cout << x << " ";
    return 0;
}