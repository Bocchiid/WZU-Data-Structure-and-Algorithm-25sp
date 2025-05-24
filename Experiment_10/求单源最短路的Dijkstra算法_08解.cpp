/** 该解法图的存储为邻接矩阵实现 */
/** 该解法的dijkstra为BF实现 */

#define vc vector
#define pb push_back

#define INF 0x3f3f3f3f

#include <iostream>
#include <vector>
using namespace std;

int n, m;

vc<vc<int>> a;
vc<int> dist;
vc<int> path;
vc<bool> visited;

void dijkstra(int s)
{
    int i, j;
    int v;
    /** Init dist */
    dist.assign(n, INF);
    /** Init path */
    path.assign(n, -1);
    /** Init visited */
    visited.assign(n, false);

    dist[s] = 0;
    path[s] = -1;

    for (i = 0; i < n; i++)
    {
        int u, mind;

        u = 0;
        mind = INF;
        /** Find shortest dist vertex u which is not visited */
        for (j = 0; j < n; j++)
            if (!visited[j] && dist[j] < mind)
            {
                mind = dist[j];
                u = j;
            }
        /** Visit vertex u */
        visited[u] = true;
        /** Try to update shortest dist */
        for (v = 0; v < n; v++)
        { /** Find edges with beginning vertex u */
            if (a[u][v] != INF)
            {
                int w = a[u][v];

                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    path[v] = u;
                }
            }
        }
    }
}

int main()
{
    int i, j, k;
    /** Input */
    cin >> n >> m;
    /** Input edge */
    /** Init matrix */
    a.assign(n, vc<int>(n, INF));

    for (i = 0; i < m; i++)
    {
        int u, v, w;

        cin >> u >> v >> w;
        a[u][v] = w;
    }
    /** Do dijkstra */
    dijkstra(0);
    /** Output path */
    for (i = 0; i < n; i++)
        cout << "v[" << i << "]: dist=" << dist[i] << ", path=" << path[i] << endl;

    return 0;
}
