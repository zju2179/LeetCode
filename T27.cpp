#include<iostream>
#include<vector>
using namespace std;
int removeElement(vector<int>& nums, int val) {
    int i=0,j=nums.size()-1;
    while(i<=j)
    {
        if(nums[i]==val)
        {
            swap(nums[i],nums[j]);
            i--;
            j--;
        }
        i++;
    }
    return j+1;
    // int cnt=0;
    // int n=nums.size();
    // for(int i=0;i<n;i++)
    // {
    //     if(nums[i]!=val)
    //     {
    //         nums[cnt++]=nums[i];
    //     }
    // }
    // return cnt;
}
int main()
{
    vector<int> nums={3,2,2,3};
    int val=3;
    int cnt=removeElement(nums,val);
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