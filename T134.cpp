#include<iostream>
#include<vector>
using namespace std;
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n=gas.size();
    int idx=0;
    int curSum=0,totalSum=0;
    for(int i=0;i<n;i++)
    {
        curSum+=gas[i]-cost[i];
        totalSum+=gas[i]-cost[i];
        if(curSum<0)
        {
            idx=(i+1)%n;
            curSum=0;
        }
    }
    if(totalSum<0)  return -1;
    return idx;
    // //第二次优化
    // int n = gas.size();
    // for(int i=0;i<n;i++)
    // {
    //     int j = i;//i能到达的最远位置
    //     int remain=gas[i];
    //     while(remain-cost[j]>=0)
    //     {
    //         remain=remain-cost[j]+gas[(j+1)%n];
    //         j=(j+1)%n;
    //         if(j == i)
    //             return i;
    //     }
    //     if(j<i)//反证法i+1<=k<=j之间的作为起点都不能绕一圈
    //         return -1;
    //     i=j;//最后for有i++,相当于让i更新到了j+1
    // }
    // return -1;
    // //第一次优化
    // int n = gas.size();
    // vector<int> farIndex;
    // for(int i=0;i<n;i++)
    //     farIndex.push_back(-1);
    // vector<int> farIndexRemain;
    // for(int i=0;i<n;i++)
    //     farIndexRemain.push_back(-1);
    // for(int i=0;i<n;i++)//遍历每一个起点
    // {
    //     int j = i;//j为以i作为起点能走到的最远终点
    //     int remain = gas[i];//当前剩余的汽油量
    //     while(remain-cost[j]>=0)//判断能否跳到j的下一位置j+1
    //     {
    //         remain-=cost[j];//先让其跳到下一位置，但先不加上下一位置的油
    //         j=(j+1)%n;
    //         if(farIndex[j]!=-1)
    //         {//若遇到之前更新过的点，即从j位置开始(有加上gas[j])能跳到的最远位置farIndex[j]>j
    //             remain=remain+farIndexRemain[j];
    //             j=farIndex[j];
    //         }
    //         else
    //         {//farIndex未更新过
    //             remain=remain+gas[j];
    //         }
    //         if(j==i)
    //             return i;
    //     }
    //     farIndex[i]=j;
    //     farIndexRemain[i]=remain;
    // }
    // return -1;
    
    // int n = gas.size();
    // for(int start=0;start<n;start++)
    // {
    //     int cnt=0;
    //     int i=start, cur_gas=gas[i];
    //     while(cnt<n)
    //     {
    //         if(cur_gas<cost[i])
    //             break;
    //         cur_gas=cur_gas-cost[i]+gas[(i+1)%n];
    //         i=(i+1)%n;
    //         cnt++;
    //     }
    //     if(cnt == n)
    //         return start;
    // }
    // return -1;
}
int main()
{
    vector<int> gas={2,3,4}, cost={3,4,3};
    int res = canCompleteCircuit(gas,cost);
    cout<<res<<endl;
    return 0;
}