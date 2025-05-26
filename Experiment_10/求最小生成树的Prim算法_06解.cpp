/** prim其实就是特殊的dijkstra */

/** 该解法图的存储为直接存储边实现 */
/** 该解法的prim为BF实现 */

#define vc vector
#define pb push_back

#define INF 0x3f3f3f3f

#include <iostream>
#include <vector>
using namespace std;

struct edge
{
    int u;
    int v;
    int w;
};

int n, m;

vc<edge> a;
vc<int> cost;
vc<int> parent;

int prim(int s)
{
    int i, j;
    /** Init cost */
    cost.assign(n, INF);
    cost[s] = 0;

    for (j = 0; j < 2 * m; j++)
    {
        if (a[j].u == s)
        {
            int v = a[j].v;
            int w = a[j].w;
            /** Actually, cost[s] == 0 */
            cost[v] = w; /** cost[v] = cost[u] + w */
        }
    }
    /** Init parent */
    parent.assign(n, 0);
    /** Make weight */
    int weight = 0;
    /** Visit vertex s */
    weight += cost[s];
    cost[s] = 0;
    parent[s] = -1;

    for (i = 1; i < n; i++)
    {
        int u, mind;

        u = -1;
        mind = INF;
        /** Find min cost vertex u */
        for (j = 0; j < n; j++)
            if (cost[j] && cost[j] < mind)
            {
                mind = cost[j];
                u = j;
            }
        /** If exists */
        if (u != -1)
        { /** Visit vertex u */
            weight += cost[u];
            cost[u] = 0;
            /** Try to update min cost */
            for (j = 0; j < 2 * m; j++)
            {
                if (a[j].u == u)
                {
                    int v = a[j].v;
                    int w = a[j].w;
                    /** Actually, cost[u] == 0 */
                    if (w < cost[v]) /** cost[u] + w < cost[v] */
                    {
                        cost[v] = w; /** cost[v] = cost[u] + w */
                        parent[v] = u;
                    }
                }
            }
        }
        else /** Or, return -1 */
            return -1;
    }

    return weight;
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
        a.pb({v, u, w});
    }
    /** Do prim */
    int weight = prim(0);
    /** Output */
    cout << "total weight = " << weight << endl;
    /** Output parent */
    for (i = 0; i < n; i++)
        cout << parent[i] << " ";

    return 0;
}
