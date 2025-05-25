/** 该解法图的存储为邻接矩阵实现 */

#define INF 0x3f3f3f3f

#include <stdio.h>

int n, m;

int a[101][101];
int dist[101];
int path[101];

int bellman_ford(int s)
{
    int i, j;
    int v;
    /** Init dist */
    for (i = 0; i < n; i++)
        dist[i] = INF;
    /** Init path */
    for (i = 0; i < n; i++)
        path[i] = -1;
    /** Visit vertex s */
    dist[s] = 0;
    path[s] = -1;
    /** Visit other vertexes */
    for (i = 1; i < n; i++)
    { /** Visit every edge */
        for (j = 0; j < n; j++)
        {
            for (v = 0; v < n; v++)
            {
                if (a[j][v] != INF)
                {
                    int u = j;
                    int w = a[u][v];
                    /** Try to update shortest dist */
                    if (dist[u] + w < dist[v])
                    {
                        dist[v] = dist[u] + w;
                        path[v] = u;
                    }
                }
            }
        }
    }
    /** Check negative circle */
    for (j = 0; j < n; j++)
    {
        for (v = 0; v < n; v++)
        {
            if (a[j][v] != INF)
            {
                int u = j;
                int w = a[u][v];

                if (dist[u] + w < dist[v])
                    return 0;
            }
        }
    }

    return 1;
}

int main()
{
    int i, j;
    /** Input */
    scanf("%d %d", &n, &m);
    /** Input edge */
    /** Init a */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = INF;
        }
    }

    for (i = 0; i < m; i++)
    {
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);
        a[u][v] = w;
    }
    /** Do bellman_ford */
    int flag = bellman_ford(0);
    /** Output */
    printf("BF returns %d\n", flag);
    /** Output dist */
    for (i = 0; i < n; i++)
        printf("dist[%d] = %d\n", i, dist[i]);

    return 0;
}
