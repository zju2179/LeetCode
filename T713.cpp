#include<iostream>
#include<vector>
using namespace std;
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int res = 0;
    int n = nums.size();
    int left = 0, cur = 1;
    for(int right = 0; right < n; right++)
    {
        cur *= nums[right];
        if(right == 0)
        {
           if(cur < k)  res++; 
        }
        else
        {
            while(left <= right && cur >= k)
            {
                cur /= nums[left];
                left++;
            }
            res += right - left + 1;
        }
    }
    return res;
}
int main()
{
    vector<int> nums = {10,5,2,6};
    int k = 100;
    cout<<numSubarrayProductLessThanK(nums, k)<<endl;
    return 0;
}