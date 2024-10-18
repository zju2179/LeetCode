#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compareSecond(const pair<int,int> a, const pair<int,int> b)
{
    return a.second < b.second;
}
vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    int n = nums.size();
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++)
    {
        a[i] = make_pair(nums[i], i);
    }
    sort(a.begin(), a.end());
    vector<int> ans(n, 0);
    int i = 0;
    while(i < n)
    {
        int st = i;
        i++;
        while(i < n && a[i].first - a[i-1].first <= limit)
            i++;
        vector<pair<int, int>> sub(a.begin()+st, a.begin()+i);
        sort(sub.begin(), sub.end());
        vector<int> idx;
        for(auto p: sub)
            idx.push_back(p.second);
        sort(idx.begin(), idx.end());
        for(int j = 0; j < sub.size(); j++)
        {
            pair<int,int> p = sub[j];
            ans[idx[j]] = p.first;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {5,1,4,3,2};
    int limit = 1;
    vector<int> ans = lexicographicallySmallestArray(nums, limit);
    for(int x: ans)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}