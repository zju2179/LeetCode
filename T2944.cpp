#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// int dfs(int i,vector<int> prices)
// {
//     if(i >= ((prices.size()+1)/2))
//         return prices[i-1];
//     int res = INT_MAX;      
//     for(int j = i+1; j <= 2*i+1; j++)
//     {
//         res = min(res, dfs(j, prices));
//     }
//     return res + prices[i-1];
// }
int res = INT_MAX;
void dfs(int i, vector<int> prices, int sum, int n)
{// 获得从第i个水果开始到第n个水果并且买第i个水果的最小价格
    if(2*i >= n)
    {
        res = min(res, sum+prices[i-1]);
        return;
    }
    sum += prices[i-1];
    for(int j = i+1; j<=2*i+1; j++)
    {
        dfs(j, prices, sum, n);
    }
}
const int N = 1010;
int f[N];
int minimumCoins(vector<int>& prices) {
    int n = prices.size();
    for(int i=n; i>0; i--)
    {
        if(2*i >= n)
            f[i] = prices[i-1];
        else
        {
            int res = INT_MAX; // res表示从j到n水果所需花费的价格的最小值
            for(int j = i+1; j <= 2*i+1; j++) // j表示买了第i个水果之后将要买的下一个水果
            {
                res = min(res, f[j]);
            }
            f[i] = res + prices[i-1];
        }
        
    }
    return f[1];
}

int main()
{
    vector<int> prices = {3,1,2};
    cout<<minimumCoins(prices)<<endl;
    return 0;
}