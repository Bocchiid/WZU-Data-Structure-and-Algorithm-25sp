/** 该解法图的存储为直接存储边实现 */

#define vc vector
#define pb push_back

#define INF 0x3f3f3f3f

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge
{
    int u;
    int v;
    int w;
};

bool cmp(const edge &a, const edge &b)
{
    if (a.u < b.u)
        return true;
    else if (a.u == b.u && a.v < b.v)
        return true;

    return false;
}

int n, m;

vc<edge> a;
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
        for (j = 0; j < m; j++)
        {
            int u = a[j].u;
            int v = a[j].v;
            int w = a[j].w;
            /** Try to update shortest dist */
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                path[v] = u;
            }
        }
    }
    /** Check negative circle */
    for (j = 0; j < m; j++)
    {
        int u = a[j].u;
        int v = a[j].v;
        int w = a[j].w;

        if (dist[u] + w < dist[v])
            return false;
    }

    return true;
}

int main()
{
    int i, j;
    /** Input */
    cin >> n >> m;
    /** Input edge */
    for (i = 0; i < m; i++)
    {
        int u, v, w;

        cin >> u >> v >> w;
        a.pb({u, v, w});
    }
    /** Sort edges by vertex u and v */
    sort(a.begin(), a.end(), cmp);
    /** Do bellman_ford */
    bool flag = bellman_ford(0);
    /** Output */
    cout << "BF returns " << flag << endl;
    /** Output dist */
    for (i = 0; i < n; i++)
        cout << "dist[" << i << "] = " << dist[i] << endl;

    return 0;
}
