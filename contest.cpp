#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXV = 1e9 + 10;
long long maximumTotalDamage(vector<int>& power) {
    sort(power.begin(), power.end());
    long long res = 0;
    // int n = power.size();
    vector<int> cnt(MAXV, 0);
    vector<int> a;
    for(int x: power)
    {
        if(cnt[x] == 0)
            a.push_back(x);
        cnt[x]++;
    }    
    int n = a.size();
    // vector<long long> dp(n, 0);
    long long dp_dec = 0, dp_i, dp_inc;
    dp_i = dp_inc = a[0] * cnt[a[0]];
    int last = a[0];
    for(int i = 1; i < a.size(); i++)
    {
        // dp[i+1]
        if(a[i] - last == 1)
        {
            last = a[i];
            dp_inc = max(dp_i, dp_dec + a[i] * cnt[a[i]]);
        }
        else
        {
            last = a[i];
            dp_inc = dp_i + a[i] * cnt[a[i]];
        }
        dp_dec = dp_i;
        dp_i = dp_inc;
    }
    return dp_inc;
}

int main()
{
    vector<int> power = {1,1,3,4};
    cout<<maximumTotalDamage(power)<<endl;
    return 0;
}