#include<iostream>
#include<vector>
using namespace std;
int res=0;
// #define cash 0  //持有现金，卖出股票，加钱
// #define stock 1 //持有股票，购买股票，扣钱
// DFS
// void dfs(vector<int> prices, int index, int len, int status, int profit)
// {
//     if(index == len)
//     {
//         res=max(res, profit);
//         return;
//     }
//     dfs(prices, index+1, len, status, profit);
//     if(status == 0)
//     {
//         dfs(prices, index+1, len, 1, profit-prices[index]);
//     }
//     else
//     {
//         dfs(prices, index+1, len, 0, profit+prices[index]);
//     }
// }
// int maxProfit(vector<int>& prices) {
//     int len=prices.size();
//     dfs(prices, 0, len, 0, 0);
//     return res;
// }
const int N = 30010;
int f[N][2];
//dp
// int maxProfit(vector<int>& prices) {
//     int n = prices.size();
//     if(n < 2)
//         return 0;
//     f[0][cash] = 0;
//     f[0][stock] = -prices[0];
//     for(int i=1;i<n;i++)
//     {
//         f[i][cash]=max(f[i-1][cash], f[i-1][stock] + prices[i]);
//         f[i][stock]=max(f[i-1][stock], f[i-1][cash] - prices[i]);
//     }
//     return f[n-1][cash];
// }

//dp空间优化第一步
// int cash[N],stock[N];
// int maxProfit(vector<int>& prices) {
//     int n=prices.size();
//     if(n<2) return 0;
//     cash[0]=0;
//     stock[0]=-prices[0];
//     for(int i = 1; i < n; i++)
//     {
//         cash[i]=max(cash[i-1], stock[i-1] + prices[i]);
//         stock[i]=max(stock[i-1], cash[i-1] - prices[i]);
//     }
//     return cash[n-1];
// }

//dp空间优化第二步,使用滚动数组
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    if(n<2) return 0;
    int cash = 0, stock = -prices[1];
    int preCash = 0, preStock = -prices[0];
    for(int i = 1; i < n; i++)
    {
        cash = max(cash, preStock + prices[i]);
        stock = max(stock, preCash - prices[i]);
        preCash = cash;
        preStock = stock;
    }
    return cash;
}
int main()
{
    vector<int> nums={7,1,5,3,6,4};
    int ans = maxProfit(nums);
    cout<<ans<<endl;
    return 0;
}