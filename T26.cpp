#include<iostream>
#include<vector>
using namespace std;
int removeDuplicate(vector<int>& nums) {
    int i=0,j=1;
    while(j<nums.size())
    {
        if(nums[i]<nums[j])
        {
            nums[i+1]=nums[j];
            i++;
        }
        j++;
    }
    return i+1;
    // int cnt=1,n=nums.size();
    // for(int i=1;i<n;i++)
    // {
    //     if(nums[i]>nums[i-1])
    //     {
    //         nums[cnt++]=nums[i];
    //     }
    // }
    // return cnt;
}
int main()
{
    vector<int> nums={1,1,2};
    int cnt=removeDuplicate(nums);
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