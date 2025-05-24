/** 该解法图的存储为邻接矩阵实现 */
/** 该解法的dijkstra为堆优化实现 */

#define vc vector
#define pb push_back

#define INF 0x3f3f3f3f

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        if (a.first > b.first)
            return true;
        else if (a.first == b.first && a.second > b.second)
            return true;

        return false;
    }
};

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

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({dist[s], s});

    while (!pq.empty())
    { /** Get shortest dist vertex u */
        int u = pq.top().second;
        pq.pop();
        /** If visited, continue */
        if (visited[u])
            continue;
        /** Or visit vertex u */
        visited[u] = true;
        /** Try to update shortest dist */
        for (v = 0; v < a[u].size(); v++)
        { /** Find edges with beginning vertex u */
            if (a[u][v] != INF)
            {
                int w = a[u][v];

                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    path[v] = u;
                    /** Add vertex whose shortest dist was updated to heap */
                    pq.push({dist[v], v});
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
