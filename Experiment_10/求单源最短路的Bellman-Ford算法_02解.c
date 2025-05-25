/** 该解法图的存储为直接存储边实现 */

#define INF 0x3f3f3f3f

#include <stdio.h>
#include <stdlib.h>

typedef struct edge
{
    int u;
    int v;
    int w;
} edge;

int cmp(const void *a, const void *b)
{
    edge A = *(edge *)a;
    edge B = *(edge *)b;

    if (A.u > B.u)
        return 1;
    else if (A.u == B.u && A.v > B.v)
        return 1;

    return -1;
}

int n, m;

edge a[10001];
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
            return 0;
    }

    return 1;
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
        a[i] = ed;
    }
    /** Sort edges by u and v */
    qsort(a, m, sizeof(edge), cmp);
    /** Do bellman_ford */
    int flag = bellman_ford(0);
    /** Output */
    printf("BF returns %d\n", flag);
    /** Output dist */
    for (i = 0; i < n; i++)
        printf("dist[%d] = %d\n", i, dist[i]);

    return 0;
}
