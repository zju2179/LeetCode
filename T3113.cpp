#include<iostream>
#include<utility>
#include<vector>
#include<stack>

using namespace std;

long long numberOfSubarrays(vector<int>& nums) {
    long long res = nums.size();
    int n = nums.size();
    stack<pair<int, int>> s; // <idx, cnt>
    for(int i = 0; i < n; i++)
    {
        int x = nums[i], cnt = 0;
        while(!s.empty() && x > nums[s.top().first])
            s.pop();
        if(!s.empty() && x == nums[s.top().first])
        {
            cnt = s.top().second;
            res += cnt;
            s.pop();
        }
        cnt++;
        s.push({i, cnt});
    }
    return res;
}
int main()
{
    vector<int> nums = {1,4,3,3,2};
    cout<<numberOfSubarrays(nums)<<endl;
    return 0;
}