/** 该解法图的存储为邻接矩阵实现 */
/** 该解法的dijkstra为堆优化实现 */

#define INF 0x3f3f3f3f

#include <stdio.h>

typedef struct vertex
{
    int dist;
    int idx;
} vertex;

int n, m;

int a[101][101];
int dist[101];
int path[101];
int visited[101];
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
        if (pq[p / 2].dist > pq[p].dist ||
            pq[p / 2].dist == pq[p].dist && pq[p / 2].idx > pq[p].idx)
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
        if (i < size && (pq[i].dist > pq[i + 1].dist ||
                         pq[i].dist == pq[i + 1].dist && pq[i].idx > pq[i + 1].idx))
            i++;

        if (pq[i].dist < pq[p].dist ||
            pq[i].dist == pq[p].dist && pq[i].idx < pq[p].idx)
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

    init();

    vertex x;
    x.dist = dist[s];
    x.idx = s;
    Insert(x);

    while (size != 0)
    { /** Get shortest dist vertex u */
        int u = Delete().idx;
        /** If visited, continue */
        if (visited[u])
            continue;
        /** Or, visit vertex u */
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
                    /** Add vertex whose shortest dist was updated */
                    x.dist = dist[v];
                    x.idx = v;
                    Insert(x);
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
