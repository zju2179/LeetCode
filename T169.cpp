#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
const int N=50010;
int cnt[N];

int majorityElement(vector<int>& nums) {
    // 摩尔投票法：
    int candidate_num=nums[0];
    int count=1;
    for(int i=1;i<nums.size();i++)
    {
        if(candidate_num==nums[i])
        {
            count++;
        }
        else
        {
            count--;
            if(count==0)
            {
                candidate_num=nums[i];
                count=1;
            }
        }
    }
    return candidate_num;
    // unordered_map<int,int> hashmap;
    // for(auto x:nums)
    // {
    //     hashmap[x]++;
    // }
    // for(auto x:hashmap)
    // {
    //     if(x.second>nums.size()/2)
    //     {
    //         return x.first;
    //     }
    // }
    // return -1;
}
int main()
{
    vector<int> nums={3,2,3,3,1,3,4};
    int res=majorityElement(nums);
    cout<<res<<endl;
    return 0;
}