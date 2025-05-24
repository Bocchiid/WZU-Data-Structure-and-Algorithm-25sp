/** 该解法图的存储为邻接表实现 */
/** 该解法的邻接表为链表实现 */
/** 该解法的dijkstra为BF实现 */

#define INF 0x3f3f3f3f

#include <stdio.h>
#include <stdlib.h>

typedef struct edge
{
    int v;
    int w;
    struct edge *next;
} edge;

edge *createEdge(int v, int w)
{
    edge *ed = (edge *)malloc(sizeof(edge) * 1);
    ed->v = v;
    ed->w = w;
    ed->next = NULL;

    return ed;
}

int n, m;

edge *a[101];
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
        edge *p = a[u]->next;

        while (p)
        {
            int v = p->v;
            int w = p->w;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                path[v] = u;
            }

            p = p->next;
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
        a[i] = createEdge(0, 0);

    for (i = 0; i < m; i++)
    {
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);
        edge *ed = createEdge(v, w);

        ed->next = a[u]->next;
        a[u]->next = ed;
    }
    /** Do dijkstra */
    dijkstra(0);
    /** Output path */
    for (i = 0; i < n; i++)
        printf("v[%d]: dist=%d, path=%d\n", i, dist[i], path[i]);

    return 0;
}
