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
int d[N][N];
const int INF = 1e9 + 7;
bool st[N];

void dijkstra_adTable()
{
}
int g[N][N];
void floyd_matrix()
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (d[i][k] != INF && d[k][j] != INF && d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    fill(g[0], g[0] + N * N, INF);
    fill(d[0], d[0] + N * N, INF);
    for (int i = 0; i < n; i++)
        d[i][i] = 0;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // G[a].push_back({b, c});
        // G[b].push_back({a, c});
        // g[a][b] = g[b][a] = min(g[a][b], c);
        d[a][b] = d[b][a] = min(d[a][b], c);
    }
    // dijkstra_adTable();
    floyd_matrix();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << (d[i][j] == INF ? -1 : d[i][j]);
            if (j < n - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}