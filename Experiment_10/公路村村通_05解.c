/** 本题其实就是7-3prim算法的实现 */
/** 由于题目不要求输出树的序列, 故不需要parent数组 */

/** 该解法图的存储为邻接矩阵实现 */
/** 该解法的prim为堆优化实现 */

#define INF 0x3f3f3f3f

#include <stdio.h>

typedef struct vertex
{
    int cost;
    int idx;
} vertex;

int n, m;

int a[1001][1001];
int cost[1001];
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
    int v;
    /** Make heap */
    init();
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
        for (v = 1; v <= n; v++)
        {
            if (a[u][v] != INF)
            {
                int w = a[u][v];
                /** Actually, cost[u] == 0 */
                if (w < cost[v]) /** cost[u] + w < cost[v] */
                {
                    cost[v] = w; /** cost[v] = cost[u] + w */
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
