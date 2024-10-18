#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;
int countPairs(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    unordered_map<int, int> cnt;
    int res = 0;
    for (int x : nums)
    {
        unordered_set<int> st = {x};
        string s = to_string(x);
        int n = s.length();
        for (int i = 0; i < n; i++)
        { // 枚举x所有可能的交换的数位
            for (int j = i + 1; j < n; j++)
            {
                swap(s[i], s[j]);
                st.insert(stoi(s));
                swap(s[i], s[j]);
            }
        }

        for (int v : st)
            res += cnt[v];

        cnt[x]++;
    }
    return res;
}
int main()
{
    vector<int> nums = {3, 12, 30, 17, 21};
    cout << countPairs(nums) << endl;
    return 0;
}