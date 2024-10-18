#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int len=0;
    int k=2;
    for(auto x:nums)
    {
        if(len<k||nums[len-k]!=x)
        {
            nums[len++]=x;
        }
    }
    return len;
    // int i=0,j=1;
    // int n=nums.size();
    // while(j<n)
    // {
    //     if(nums[i]<nums[j])
    //     {
    //         nums[i+1]=nums[j];
    //         i++;
    //     }
    //     else//nums[i]==nums[j]
    //     {
    //         nums[i+1]=nums[j];
    //         i++;
    //         while(j+1<n&&nums[j]==nums[j+1])
    //         {
    //             j++;
    //         }
    //     }
    //     j++;
    // }
    // return i+1;
}

int main()
{
    vector<int> nums={0,0,1,1,1,1,2,3,3};
    int cnt=removeDuplicates(nums);
    bool isfirst=true;
    for(int i=0;i<cnt;i++)
    {
        if(!isfirst)
            cout<<" ";
        else
            isfirst=false;
        cout<<nums[i];
    }
    return 0;
}