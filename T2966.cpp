#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> divideArray(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    for(int i = 0; i < n; i += 3)
    {
        if(i+2<n && nums[i+2] - nums[i] <= k)
            res.push_back({nums[i], nums[i+1], nums[i+2]});
    }
    if(res.size() < n/3)
        return {};
    return res;
}

int main()
{
    vector<int> nums = {1,3,4,8,7,9,3,5,1};
    int k = 2;
    vector<vector<int>> res = divideArray(nums,k);
    return 0;
}