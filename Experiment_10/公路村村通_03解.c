/** 本题其实就是7-3prim算法的实现 */

/** 该解法图的存储为直接存储边实现 */
/** 该解法的prim为堆优化实现 */

#define INF 0x3f3f3f3f

#include <stdio.h>

typedef struct vertex
{
    int cost;
    int idx;
} vertex;

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
/** Heap */
vertex pq[10001];
int size;

void swap(vertex *a, vertex *b)
{
    vertex temp = *a;
    *a = *b;
    *b = temp;
}

void init()
{
    size = 0;
}

void percolateUp(int p)
{
    while (p > 1)
    {
        if (pq[p / 2].cost > pq[p].cost ||
            pq[p / 2].cost == pq[p].cost && pq[p / 2].idx > pq[p].idx)
        {
            swap(&pq[p / 2], &pq[p]);
            p /= 2;
        }
        else
            break;
    }
}

void percolateDown(int p)
{
    int i;

    for (i = p * 2; i <= size; i *= 2)
    {
        if (i < size && (pq[i].cost > pq[i + 1].cost ||
                         pq[i].cost == pq[i + 1].cost && pq[i].idx > pq[i + 1].idx))
            i++;

        if (pq[i].cost < pq[p].cost ||
            pq[i].cost == pq[p].cost && pq[i].idx > pq[p].idx)
        {
            swap(&pq[i], &pq[p]);
            p = i;
        }
        else
            break;
    }
}

void Insert(vertex x)
{
    size++;
    pq[size] = x;
    percolateUp(size);
}

vertex Delete()
{
    vertex ret = pq[1];

    pq[1] = pq[size];
    size--;
    percolateDown(1);

    return ret;
}

int prim(int s)
{
    int i, j;
    /** Init parent */
    for (i = 1; i <= n; i++)
        parent[i] = 1;
    /** Make heap */
    init();
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
            /** Push vertex whose min cost was updated */
            vertex x;
            x.cost = cost[v];
            x.idx = v;
            Insert(x);
        }
    }
    /** Make counting */
    int cnt = 0;
    /** Make weight */
    int weight = 0;
    /** Visit vertex s */
    weight += cost[s];
    cost[s] = 0;
    cnt++;
    parent[s] = -1;

    while (size != 0)
    { /** Get min cost vertex u */
        int u = Delete().idx;
        /** If in tree(cost == 0), continue */
        if (!cost[u])
            continue;
        /** Or, visit vertex u */
        weight += cost[u];
        cost[u] = 0;
        cnt++; /** Counting++ */
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
                    /** Push vertex whose min cost was updated */
                    vertex x;
                    x.cost = cost[v];
                    x.idx = v;
                    Insert(x);
                }
            }
        }
    }

    if (cnt == n)
        return weight;

    return -1;
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
