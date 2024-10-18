#include <iostream>
using namespace std;
int calcCnt(int x)
{
    int res = 1;
    int d = 2;
    int tempX = x;
    while (d * d <= x)
    {
        if (x % d == 0)
        {
            while (x % d == 0)
            {
                x /= d;
                res++;
            }
            cout << d << " " << res << endl;
        }
        d++;
    }
    if (x > 1 && x != tempX)
        res++;
    cout << res << endl;
    return res;
}
int nonSpecialCount(int l, int r)
{
    int res = 0;

    for (int i = l; i <= r; i++)
    {
        cout << i << ":" << endl;
        if (calcCnt(i) != 2)
            res++;
    }
    return res;
}
int main()
{
    cout << nonSpecialCount(5, 7) << endl;
    return 0;
}