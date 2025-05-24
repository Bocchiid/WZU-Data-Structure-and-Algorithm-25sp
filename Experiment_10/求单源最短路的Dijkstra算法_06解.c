/** 该解法图的存储为邻接矩阵实现 */
/** 该解法的dijkstra为BF实现 */

#define INF 0x3f3f3f3f

#include <stdio.h>

int n, m;

int a[101][101];
int dist[101];
int path[101];
int visited[101];

void dijkstra(int s)
{
    int i, j;
    int v;
    /** Init dist */
    for (i = 0; i < n; i++)
        dist[i] = INF;
    /** Init path */
    for (i = 0; i < n; i++)
        path[i] = -1;
    /** Init visited */
    for (i = 0; i < n; i++)
        visited[i] = 0;

    dist[s] = 0;
    path[s] = -1;

    for (i = 0; i < n; i++)
    {
        int u, mind;

        u = 0;
        mind = INF;
        /** Find shortest dist vertex u */
        for (j = 0; j < n; j++)
            if (!visited[j] && dist[j] < mind)
            {
                mind = dist[j];
                u = j;
            }
        /** Visit vertex u */
        visited[u] = 1;
        /** Try to update shortest dist */
        for (v = 0; v < n; v++)
        {
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
    int i, j;
    /** Input */
    scanf("%d %d", &n, &m);
    /** Input edge */
    /** Init a */
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            a[i][j] = INF;

    for (i = 0; i < m; i++)
    {
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);
        a[u][v] = w;
    }
    /** Do dijkstra */
    dijkstra(0);
    /** Output path */
    for (i = 0; i < n; i++)
        printf("v[%d]: dist=%d, path=%d\n", i, dist[i], path[i]);

    return 0;
}
