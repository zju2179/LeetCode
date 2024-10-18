#include<iostream>
#include<vector>
using namespace std;
bool arrive=false;
void dfs(vector<int> nums, int index)
{
    if(index>=nums.size())
    {
        arrive=true;
        // cout<<"success!"<<endl;
        return;
    }
    if(index+nums[index]>=nums.size())
    {
        arrive=true;
        // cout<<"success!"<<endl;
        return;
    }
    for(int d=nums[index]; d>=1; d--)
    {
        dfs(nums, index+d);
    }
}
const int N = 10010;
bool st[N];
bool canJump(vector<int>& nums) {
    int k=0;//表示能跳到的最远的坐标
    for(int i=0;i<nums.size();i++)
    {//i表示当前的起跳点
        if(i>k)//当起跳点超过了能到达的最远坐标，说明此时i位于一个不可能跳到的位置 
            return false;
        k=max(k, i+nums[i]);
    }
    return true;
    // st[0]=true;
    // for(int i=0;i<nums.size();i++)
    // {
    //     if(st[i]==true)
    //     {
    //         for(int d=nums[i];d>=0;d--)
    //         {
    //             if(i+d<nums.size())
    //                 st[i+d]=true;
    //         }
    //     }
    //     if(st[nums.size()-1])   return true;
    // }
    // return st[nums.size()-1];
}

int main()
{
    vector<int> nums={2,3,1,1,4};
    bool res = canJump(nums);
    cout<<res<<endl;
    return 0;
}