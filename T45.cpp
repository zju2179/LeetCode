#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int N=11010;
int level[N];
bool inQueue[N];
int jump(vector<int>& nums) {
//求出每轮（第ans轮）的起跳区间的所有起点能跳到的最远点，得到跳跃次数
    int ans=0;
    int start=0,end=1; //起跳点区间[start, end)
    while(end<nums.size())
    {
        int maxPos=0; //当前起跳点区间的所有起点能跳到的最远终点
        for(int i=start; i<end; i++)
        {
            maxPos=max(maxPos,i+nums[i]);
        }
        start = end;
        end = maxPos + 1;
        ans++;
    }
    return ans;
    // queue<int> q;
    // int res=N;
    // q.push(0);
    // inQueue[0]=true;
    // while(!q.empty())
    // {
    //     int cur=q.front();
    //     q.pop();
    //     if(cur>=nums.size()-1)
    //         res=min(res,level[cur]);
    //     if(cur<nums.size())
    //     {
    //         for(int j=nums[cur];j>0;j--)
    //         {
    //             if(!inQueue[cur+j])
    //             {
    //                 level[cur+j]=level[cur]+1;
    //                 q.push(cur+j);
    //                 inQueue[cur+j]=true;
    //                 if(cur+j>=nums.size()-1)
    //                     res=min(res,level[cur+j]);
    //             }
    //         }
    //     }
    // }
    // return res;
}
int jump2(vector<int> &nums)
{
    int maxPos=0;
    int end=0, ans=0;
    for(int i=0;i<nums.size()-1;i++)
    {//扫过的起跳点区间[i,end]
        maxPos=max(maxPos,i+nums[i]);
        if(i==end)
        {//走完当前起跳点区间，更新从该起跳点区间出发能到达的最远终点
            end=maxPos;
            ans++; //跳跃次数增加，跳向下一个起跳点区间
        }
    }
    return ans;
}
int main()
{
    vector<int> nums={9,8,2,2,0,2,2,0,4,1,5,7,9,6,6,0,6,5,0,5};
    int res = jump(nums);
    cout<<res<<endl;
    return 0;
}