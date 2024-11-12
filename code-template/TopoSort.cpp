#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 110;
int inDegree[N];
int n, m;
int g[N][N];
const int INF = 1e9 + 7;
bool inQueue[N];

vector<int> topoSort()
{
    vector<int> res;
    // queue<int> q;
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
            inQueue[i] = true;
        }
    }
    while (!q.empty())
    {
        int u = q.top();
        q.pop();
        res.push_back(u);
        for (int v = 0; v < n; v++)
        {
            if (g[u][v] && !inQueue[v])
            {
                inDegree[v]--;
                if (inDegree[v] == 0)
                {
                    q.push(v);
                    inQueue[v] = true;
                }
            }
        }
    }
    return res;
}
// void init()
// {
//     fill(g[0], g[0] + N * N, INF);

// }
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = 1;
        inDegree[b]++;
    }
    vector<int> res = topoSort();
    for (int i = 0; i < n; i++)
    {
        cout << res[i];
        if (i < n - 1)
            cout << " ";
    }
    return 0;
}