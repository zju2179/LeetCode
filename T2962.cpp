#include<iostream>
#include<algorithm>
#include<vector>
// #include<openssl/safestack>
#include<string>
using namespace std;

long long countSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    int target = 0;
    for(int x: nums)
        target = max(target, x);
    long long res = 0;
    int cnt_max = 0;
    int left = 0; // left-1是合法左端点的最大值
    for(int right = 0; right < n; right++)
    {
        int x = nums[right];
        if(x == target) cnt_max++;
        while(cnt_max >= k) // cnt_max == k
        {
            if(nums[left] == target)
                cnt_max--;
            left++;
        }// [0, left-1]是所有可能的子数组左端点的所有取值
        res += left;
    }
    return res;
}
int main()
{
    vector<int> nums = {1,3,2,3,3};
    int k = 2;
    cout<<countSubarrays(nums, k)<<endl;
    return 0;
}