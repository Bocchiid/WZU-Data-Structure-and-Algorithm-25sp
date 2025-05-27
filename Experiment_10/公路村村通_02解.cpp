/** 本题其实就是7-3prim算法的实现 */
/** 由于题目不要求输出树的序列, 故不需要parent数组 */

/** 该解法图的存储为邻接表实现 */
/** 该解法的邻接表为数组实现 */
/** 该解法的prim为BF实现 */

#define vc vector
#define pb push_back

#define INF 0x3f3f3f3f

#include <iostream>
#include <vector>
using namespace std;

int n, m;

vc<vc<pair<int, int>>> a;
vc<int> cost;

int prim(int s)
{
    int i, j;
    /** Init cost */
    cost.assign(n + 1, INF);
    cost[s] = 0;

    for (auto ed : a[s])
    {
        int v = ed.first;
        int w = ed.second;
        /** Actually, cost[s] == 0 */
        cost[v] = w; /** cost[v] = cost[s] + w */
    }
    /** Make weight */
    int weight = 0;
    /** Visit vertex s */
    weight += cost[s];
    cost[s] = 0;

    for (i = 1; i < n; i++)
    {
        int u, mind;

        u = -1;
        mind = INF;
        /** Find min cost vertex u */
        for (j = 1; j <= n; j++)
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
            for (auto ed : a[u])
            {
                int v = ed.first;
                int w = ed.second;
                /** Actually, cost[u] == 0 */
                if (w < cost[v]) /** cost[u] + w < cost[v] */
                {
                    cost[v] = w; /** cost[v] = cost[u] + w */
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
    /** Init a */
    a.resize(n + 1);

    for (i = 0; i < m; i++)
    {
        int u, v, w;

        cin >> u >> v >> w;
        a[u].pb({v, w});
        a[v].pb({u, w});
    }
    /** Do prim */
    int weight = prim(1);
    /** Output */
    cout << weight << endl;

    return 0;
}
