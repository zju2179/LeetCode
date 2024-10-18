#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotate(vector<int>& nums, int k) {
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
    // vector<int> temp=nums;
    // int n=nums.size();
    // for(int i=0;i<n;i++)
    // {
    //     swap(nums[(i+k)%n],nums[i]);
    // }
}

int main()
{
    vector<int> nums={1,2,3,4,5,6,7};
    int k=3;
    rotate(nums,k);
    bool isfirst=true;
    for(int i=0;i<nums.size();i++)
    {
        if(!isfirst)
            cout<<" ";
        else
            isfirst=false;
        cout<<nums[i];
    }
    return 0;
}