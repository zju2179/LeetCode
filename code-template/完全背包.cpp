#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
const int V = 1010;
int dp[N][V];
int n, v;
int w[N], c[N];
int choice[N][V];

int dfs(int i, int j)
{
    if (i <= 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int res = dfs(i - 1, j);
    for (int k = 1; j - k * w[i] >= 0; k++)
        res = max(res, dfs(i - 1, j - k * w[i]) + k * c[i]);
    return dp[i][j] = res;
}

int main()
{
    cin >> n >> v;
    // fill(dp[0], dp[0] + N * V, -1);
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    // cout << dfs(n, v) << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = v; j >= 0; j--)
        {
            dp[i][j] = dp[i - 1][j];
            for (int k = 1; j - k * w[i] >= 0; k++)
            {
                if (dp[i][j] < dp[i - 1][j - k * w[i]] + k * c[i])
                {
                    dp[i][j] = dp[i - 1][j - k * w[i]] + k * c[i];
                    choice[i][j] = k;
                }
            }
        }
    }
    vector<int> res;
    cout << dp[n][v] << endl;
    for (int i = n, j = v; i >= 1; i--)
    {
        if (choice[i][j] > 0)
        {
            for (int k = 0; k < choice[i][j]; k++)
                res.push_back(i);
            j -= choice[i][j] * w[i];
        }
    }
    bool isfirst = true;
    for (int i = res.size() - 1; i >= 0; i--)
    {
        if (isfirst)
            isfirst = false;
        else
            cout << " ";
        cout << res[i];
    }
    return 0;
}