#include <iostream>
using namespace std;

const int N = 110;
int father[N];
int n, m;

int findFather(int x)
{
    int tempX = x;
    while (x != father[x])
    {
        x = father[x];
    }
    int root = x;
    x = tempX;
    while (x != father[x])
    {
        int nextX = father[x];
        father[x] = root;
        x = nextX;
    }
    return root;
}

void unionSet(int a, int b)
{
    int fa = findFather(a);
    int fb = findFather(b);
    if (fa != fb)
    {
        father[fb] = fa;
    }
}
void init()
{
    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
    }
}

int main()
{
    cin >> n >> m;
    int a, b;
    init();
    while (m--)
    {
        cin >> a >> b;
        unionSet(a, b);
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (father[i] == i)
            res++;
    }
    cout << res << endl;
    return 0;
}