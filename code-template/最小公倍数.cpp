#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
// 最小公倍数 = a * b / gcd(a, b) = a / gcd(a, b) * b

int minComMultiple(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    // int a, b;
    // scanf("%d%d", &a, &b);
    // printf("%d\n", minComMultiple(a, b));
    int n, res;
    cin >> n;
    cin >> res;
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        res = gcd(res, x);
    }
    cout << res << endl;
    return 0;
}