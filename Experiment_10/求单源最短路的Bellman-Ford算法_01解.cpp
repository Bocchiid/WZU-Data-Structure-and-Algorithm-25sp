/** 该解法图的存储为邻接表实现 */
/** 该解法的邻接表为数组实现 */

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

bool bellman_ford(int s)
{
    int i, j;
    /** Init dist */
    dist.assign(n, INF);
    /** Init path */
    path.assign(n, -1);
    /** Visit vertex s */
    dist[s] = 0;
    path[s] = -1;
    /** Visit other vertexes */
    for (i = 1; i < n; i++)
    { /** Visit every edge */
        for (j = 0; j < n; j++)
        {
            for (auto ed : a[j])
            {
                int u = j;
                int v = ed.first;
                int w = ed.second;
                /** Try to update shortest dist */
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    path[v] = u;
                }
            }
        }
    }
    /** Check negative circle */
    for (j = 0; j < n; j++)
    {
        for (auto ed : a[j])
        {
            int u = j;
            int v = ed.first;
            int w = ed.second;

            if (dist[u] + w < dist[v])
                return false;
        }
    }

    return true;
}

int main()
{
    int i, j;
    /** Input */
    cin >> n >> m;
    /** Input edge */
    /** Init a */
    a.resize(n);

    for (i = 0; i < m; i++)
    {
        int u, v, w;

        cin >> u >> v >> w;
        a[u].pb({v, w});
    }
    /** Do bellman_ford */
    bool flag = bellman_ford(0);
    /** Output */
    cout << "BF returns " << flag << endl;
    /** Output dist */
    for (i = 0; i < n; i++)
        cout << "dist[" << i << "] = " << dist[i] << endl;

    return 0;
}
