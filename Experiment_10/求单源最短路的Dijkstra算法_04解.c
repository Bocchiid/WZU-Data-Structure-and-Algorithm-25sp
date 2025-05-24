/** 该解法图的存储为直接存储边实现 */
/** 该解法的dijkstra为BF实现 */

#define INF 0x3f3f3f3f

#include <stdio.h>

typedef struct edge
{
    int u;
    int v;
    int w;
} edge;

int n, m;

edge a[10001];
int dist[101];
int path[101];
int visited[101];

void dijkstra(int s)
{
    int i, j;
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
        for (j = 0; j < m; j++)
        { /** Find edges with beginning vertex u */
            if (a[j].u == u)
            {
                int v = a[j].v;
                int w = a[j].w;

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
    for (i = 0; i < m; i++)
    {
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);
        a[i].u = u;
        a[i].v = v;
        a[i].w = w;
    }
    /** Do dijkstra */
    dijkstra(0);
    /** Output path */
    for (i = 0; i < n; i++)
        printf("v[%d]: dist=%d, path=%d\n", i, dist[i], path[i]);

    return 0;
}
