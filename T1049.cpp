#include <iostream>
#include <vector>

using namespace std;
int s;
vector<int> a;
int dfs(int i, int j)
{
    if (i < 0)
        return j;
    if (j < 0)
        return INT_MIN;
    return max(dfs(i - 1, j), dfs(i - 1, j - a[i]) + a[i]);
}
int lastStoneWeightII(vector<int> &stones)
{
    int n = stones.size(), sum = 0;
    for (int x : stones)
        sum += x;
    s = sum;
    int pile = dfs(n - 1, sum / 2);
    cout << s << " " << pile << endl;
    return abs(2 * pile - sum);
}
int main()
{
    a = {2, 7, 4, 1, 8, 1};
    cout << lastStoneWeightII(a) << endl;
    return 0;
}