#include <iostream>
#include <queue>
using namespace std;

int n, m;
const int N = 110;
int a[N][N];
bool inQueue[N][N];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
class Point
{
public:
    int x, y;
    Point(int x_, int y_)
    {
        x = x_;
        y = y_;
    }
};

bool isValid(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m && !inQueue[x][y] && a[x][y] == 0)
        return true;
    return false;
}

int bfs(int x1, int y1, int x2, int y2)
{
    queue<Point> q;
    q.push(Point(x1, y1));
    inQueue[x1][y1] = true;
    int res = n * m + 1;
    int step = 0;
    while (!q.empty())
    {
        int cnt = q.size();
        while (cnt--)
        {
            Point cur = q.front();
            int x = cur.x;
            int y = cur.y;
            q.pop();
            if (x == x2 && y == y2)
            {
                res = min(res, step);
            }
            for (int i = 0; i < 4; i++)
            {
                int nextX = x + dx[i];
                int nextY = y + dy[i];
                if (isValid(nextX, nextY))
                {
                    q.push(Point(nextX, nextY));
                    inQueue[nextX][nextY] = true;
                }
            }
        }
        step++;
    }
    return res == n * m + 1 ? -1 : res;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    int res = bfs(0, 0, n - 1, m - 1);
    cout << res << endl;
    return 0;
}