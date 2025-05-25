/** 该解法图的存储为邻接表实现 */
/** 该解法的邻接表为链表实现 */

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

int bellman_ford(int s)
{
    int i, j;
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
            edge *p = a[j]->next;

            while (p)
            {
                int u = j;
                int v = p->v;
                int w = p->w;
                /** Try to update shortest dist */
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    path[v] = u;
                }

                p = p->next;
            }
        }
    }
    /** Check negative circle */
    for (j = 0; j < n; j++)
    {
        edge *p = a[j]->next;

        while (p)
        {
            int u = j;
            int v = p->v;
            int w = p->w;

            if (dist[u] + w < dist[v])
                return 0;

            p = p->next;
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
        a[i] = createEdge(0, 0);

    for (i = 0; i < m; i++)
    {
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);
        edge *ed = createEdge(v, w);

        ed->next = a[u]->next;
        a[u]->next = ed;
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
