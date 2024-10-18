#include<iostream>
#include<vector>
using namespace std;
int res = INT_MAX;
void dfs(vector<int> coins, int idx, int cnt, int sum, int amount)
{
    cout<<idx<<" "<<sum<<endl;
    if(sum == amount)
    {
        res = min(res, cnt);
        return;
    }
    if(idx >= coins.size())
        return;
    for(int i = 1; i * coins[idx] <= amount && sum + i * coins[idx] <= amount; i++)
        dfs(coins, idx + 1, cnt + i, sum + i * coins[idx], amount);
    dfs(coins, idx + 1, cnt, sum, amount);
}
const int N = 10010;
int f[N][N];
int dp(vector<int> coins, int n)
{
    if(n == 0)  return 0;
    if(n < 0)   return -1;
    int res = INT_MAX;
    for(int coin: coins)
    {
        int subproblem = dp(coins, n - coin);
        if(subproblem == -1)    continue;
        res = min(res, subproblem + 1);
    }
    if(res != INT_MAX)
        return res;
    else
        return -1;
}
int coinChange(vector<int>& coins, int amount) {
    // dfs(coins, 0, 0, 0, amount);
    return dp(coins, amount);
    // for(int k = 0; k * coins[0] <= amount; k++)
    //     f[0][k * coins[0]] = k;
    // for(int i = 1; i < coins.size(); i++)
    // {
    //     for(int j = 0; j <= amount; j++)
    //     {
    //         for(int k = 0; k * coins[i] <= amount; k++)
    //         {
    //             if(f[i][j+k*coins[i]])
    //                 f[i][j+k*coins[i]] = min(f[i][j+k*coins[i]], f[i-1][j]+k);
    //             else
    //                 f[i][j+k*coins[i]] = f[i-1][j] + k;
    //         }
    //     }
    // }
    // for(int i = 0; i < coins.size(); i++)
    //     if(f[i][amount])
    //         res = min(res, f[i][amount]);
    // if(res == INT_MAX)  return -1;
    // return res;
}
int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout<<coinChange(coins, amount);
    return 0;
}