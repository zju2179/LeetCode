#include <iostream>
using namespace std;

int n, m, cnt;
const int N = 10;
int a[N][N];
bool st[N][N];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

bool isValid(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m && !st[x][y] && a[x][y] == 0)
        return true;
    return false;
}

void dfs(int x, int y)
{
    if (x == n - 1 && y == m - 1)
    {
        cnt++;
        return;
    }
    st[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (isValid(nextX, nextY))
            dfs(nextX, nextY);
    }

    st[x][y] = false;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    dfs(0, 0);
    cout << cnt << endl;
    return 0;
}