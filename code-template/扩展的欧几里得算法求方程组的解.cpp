#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int exGcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int x_, y_;
    int g = exGcd(b, a % b, x_, y_);
    x = y_;
    y = x_ - a / b * y_;
    return g;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int x, y;
    int g = exGcd(a, b, x, y);
    cout << x << " " << y << endl;
    return 0;
}