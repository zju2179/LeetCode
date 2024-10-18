#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minimumAddedCoins(vector<int>& coins, int target) {
    int n = coins.size();
    sort(coins.begin(), coins.end());
    int i = 0, res = 0;
    int s = 1; // 当前区间能表示的数[0, s - 1]
    while(s <= target) // s-1 >= target时终止循环
    {
        if(i<n && coins[i]<=s)
        {// 将当前元素x并入当前的区间[0, s-1]
            int x = coins[i];
            s = s + x; // 区间[0, s-1] V [x, s+x-1] = [0, s+x-1];
            i++;
        }
        else // x > s
        {// 当前并入[0, s-1]的下一个元素s
            s = 2*s; // [0, s-1] V [s, 2*s-1] = [0, 2*s-1]
            res++;
        }
    }
    return res;
}

int main()
{
    vector<int> coins = {1,4,10};
    int target = 19;
    cout<<minimumAddedCoins(coins, target)<<endl;
    return 0;
}