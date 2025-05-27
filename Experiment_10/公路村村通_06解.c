/** 本题其实就是7-3prim算法的实现 */
/** 由于题目不要求输出树的序列, 故不需要parent数组 */

/** 该解法图的存储为邻接矩阵实现 */
/** 该解法的prim为BF实现 */

#define INF 0x3f3f3f3f

#include <stdio.h>

int n, m;

int a[1001][1001];
int cost[1001];

int prim(int s)
{
    int i, j;
    int v;
    /** Init cost */
    for (i = 1; i <= n; i++)
        cost[i] = INF;

    cost[s] = 0;

    for (v = 1; v <= n; v++)
    {
        if (a[s][v] != INF)
        {
            int w = a[s][v];
            /** Actually, cost[s] == 0 */
            cost[v] = w; /** cost[v] = cost[s] + w */
        }
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
            for (v = 1; v <= n; v++)
            {
                if (a[u][v] != INF)
                {
                    int w = a[u][v];
                    /** Actually, cost[u] == 0 */
                    if (w < cost[v]) /** cost[u] + w < cost[v] */
                    {
                        cost[v] = w; /** cost[v] = cost[u] + w */
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
    /** Init a */
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            a[i][j] = INF;
        }
    }

    for (i = 0; i < m; i++)
    {
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);
        a[u][v] = w;
        a[v][u] = w;
    }
    /** Do prim */
    int weight = prim(1);
    /** Output */
    printf("%d\n", weight);

    return 0;
}
