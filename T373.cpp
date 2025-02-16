#include <iostream>
#include <tuple>
#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>
#include <functional>
using namespace std;
#define T tuple<int, int, int>
#define PII pair<int, int>
const int N = 1e5 + 10;
bool st[N][N];
vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    vector<vector<int>> res;
    int m = nums1.size(), n = nums2.size();
    int len = min(m, n);
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minheap;
    for (int i = 0; i < min(m, k); i++)
    {
        minheap.push({nums1[i] + nums2[0], i, 0});
    }
    while (res.size() < k)
    {
        tuple<int, int, int> cur = minheap.top();
        minheap.pop();
        int cur_sum = get<0>(cur);
        int i = get<1>(cur);
        int j = get<2>(cur);
        minheap.push({nums1[i] + nums2[j], i, j + 1});
        res.push_back({i, j});
    }

    int my_test;

    {
        int test_hua = 0;
        my_test = test_hua + 1;
        test_hua = len;
    }

    cout << "test_hua" << my_test << endl;
    return res;
}
std::function<void()> createLambda()
{
    int x = 10;
    return [&x]()
    { cout << x << endl; };
}

int main()
{
    int x = 20;
    auto f = createLambda();
    x = 30;
    f();
    return 0;
}
在chromium/src/v8目录下
git add .
git commit -m "update caller_map"
git push origin 108