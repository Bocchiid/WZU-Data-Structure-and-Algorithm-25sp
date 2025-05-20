/** 该解法图的存储为邻接表实现 */
/** 该解法的邻接表为数组实现 */
/** 该解法的dijkstra为BF实现 */

#define vc vector
#define pb push_back

#define INF 0x3f3f3f3f

#include <iostream>
#include <vector>
using namespace std;

int n, m;

vc<vc<pair<int, int>>> a;
vc<int> dist;
vc<int> path;
vc<bool> visited;

void dijkstra(int s)
{
    int i, j;

    dist.assign(n, INF);
    path.assign(n, -1);
    visited.assign(n, false);

    dist[s] = 0;
    path[s] = -1;

    for (i = 0; i < n; i++)
    {
        int u, mind;

        u = 0;
        mind = INF;
        /** 寻找距离最小且未被访问的结点 */
        for (j = 0; j < n; j++)
            if (!visited[j] && dist[j] < mind)
            { /** 因为寻找最小距离结点为贪心, 所以不允许存在负边 */
                mind = dist[j];
                u = j;
            }
        /** 访问结点 */
        visited[u] = true;
        /** 尝试更新邻接点的最小距离 */
        for (auto ed : a[u])
        {
            int v = ed.first;
            int w = ed.second;
            /** 若经过u到达v的权比之前到达v的权更小, 则更新 */
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                path[v] = u;
            }
        }
    }
}

int main()
{
    int i, j, k;
    /** input */
    cin >> n >> m;
    /** input edge */
    a.resize(n);

    for (i = 0; i < m; i++)
    {
        int u, v, w;

        cin >> u >> v >> w;
        a[u].pb({v, w});
    }
    /** dijkstra */
    dijkstra(0);
    /** output path */
    for (i = 0; i < n; i++)
        cout << "v[" << i << "]: dist=" << dist[i] << ", path=" << path[i] << endl;

    return 0;
}
