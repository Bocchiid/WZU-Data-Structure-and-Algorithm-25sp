/** prim其实就是特殊的dijkstra */

/** 该解法图的存储为邻接表实现 */
/** 该解法的邻接表为链表实现 */
/** 该解法的prim为BF实现 */

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
int cost[101];
int parent[101];

int prim(int s)
{
    int i, j;
    /** Init parent */
    for (i = 0; i < n; i++)
        parent[i] = 0;
    /** Init cost */
    for (i = 0; i < n; i++)
        cost[i] = INF;

    cost[s] = 0;

    edge *p = a[s]->next;

    while (p)
    {
        int v = p->v;
        int w = p->w;
        /** Actually, cost[s] == 0 */
        cost[v] = w; /** cost[v] = cost[s] + w */
        parent[v] = s;

        p = p->next;
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
            edge *p = a[u]->next;

            while (p)
            {
                int v = p->v;
                int w = p->w;
                /** Actually, cost[u] == 0 */
                if (w < cost[v]) /** cost[u] + w < cost[v] */
                {
                    cost[v] = w; /** cost[v] = cost[u] + w */
                    parent[v] = u;
                }

                p = p->next;
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
    for (i = 0; i < n; i++)
        a[i] = createEdge(0, 0);

    for (i = 0; i < m; i++)
    {
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);

        edge *ed = createEdge(v, w);
        ed->next = a[u]->next;
        a[u]->next = ed;

        ed = createEdge(u, w);
        ed->next = a[v]->next;
        a[v]->next = ed;
    }
    /** Do prim */
    int weight = prim(0);
    /** Output */
    printf("total weight = %d\n", weight);
    /** Output parent */
    for (i = 0; i < n; i++)
        printf("%d ", parent[i]);

    return 0;
}
