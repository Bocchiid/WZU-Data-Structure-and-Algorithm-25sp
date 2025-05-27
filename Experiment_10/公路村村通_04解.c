/** 本题其实就是7-3prim算法的实现 */

/** 该解法图的存储为直接存储边实现 */
/** 该解法的prim为BF实现 */

#define INF 0x3f3f3f3f

#include <stdio.h>

typedef struct edge
{
    int u;
    int v;
    int w;
} edge;

int n, m;

edge a[6001];
int cost[1001];
int parent[1001];

int prim(int s)
{
    int i, j;
    /** Init parent */
    for (i = 1; i <= n; i++)
        parent[i] = 1;
    /** Init cost */
    for (i = 1; i <= n; i++)
        cost[i] = INF;

    cost[s] = 0;

    for (i = 0; i < 2 * m; i++)
    {
        if (a[i].u == s)
        {
            int v = a[i].v;
            int w = a[i].w;
            /** Actually, cost[s] == 0 */
            cost[v] = w; /** cost[v] = cost[s] + w */
        }
    }
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
    scanf("%d %d", &n, &m);
    /** Input edge */

    for (i = 0; i < m; i++)
    {
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);
        edge ed;

        ed.u = u;
        ed.v = v;
        ed.w = w;
        a[2 * i] = ed;

        ed.u = v;
        ed.v = u;
        ed.w = w;
        a[2 * i + 1] = ed;
    }
    /** Do prim */
    int weight = prim(1);
    /** Output */
    printf("%d\n", weight);

    return 0;
}
