#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, s, t;
const int N = 110;
struct Node
{
    int v, d;
};
vector<Node> G[N];
int dist[N];
const int INF = 1e9 + 7;
bool st[N];

void dijkstra_adTable()
{
    fill(dist, dist + N, INF);
    dist[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++)
        {
            if (!st[j] && dist[j] < MIN)
            {
                MIN = dist[j];
                u = j;
            }
        }
        if (u == -1)
            return;
        st[u] = true;
        for (int j = 0; j < G[u].size(); j++)
        {
            int v = G[u][j].v, d = G[u][j].d;
            if (!st[v] && dist[v] > dist[u] + d)
            {
                dist[v] = dist[u] + d;
            }
        }
    }
}
int g[N][N];
void dijkstra_matrix()
{
    fill(dist, dist + N, INF);
    dist[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++)
        {
            if (!st[j] && dist[j] < MIN)
            {
                MIN = dist[j];
                u = j;
            }
        }
        if (u == -1)
            return;
        st[u] = true;
        for (int j = 0; j < n; j++)
        {
            int v = j, utov_d = g[u][v];
            if (!st[v] && dist[v] > dist[u] + g[u][v])
            {
                dist[v] = dist[u] + g[u][v];
            }
        }
    }
}

int main()
{
    cin >> n >> m >> s >> t;
    fill(g[0], g[0] + N * N, INF);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // G[a].push_back({b, c});
        // G[b].push_back({a, c});
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    // dijkstra_adTable();
    dijkstra_matrix();
    cout << (dist[t] == INF ? -1 : dist[t]) << endl;
    return 0;
}