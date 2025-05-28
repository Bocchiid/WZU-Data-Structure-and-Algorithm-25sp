/** 本题其实就是topsort的实现 + 最早完成时间的计算 */
/** 由于题目不要求输出拓扑序列, 故不需要order数组 */

/** 该解法图的存储为直接存储边实现 */

#include <stdio.h>

typedef struct edge
{
    int u;
    int v;
    int w;
} edge;

int max(int a, int b)
{
    if (a > b)
        return a;

    return b;
}

int n, m;

edge a[10001];
int ind[101];
int elist[101];

int topsort()
{
    int i, j;
    /** Init elist */
    for (i = 0; i < n; i++)
        elist[i] = 0;
    /** Make counting */
    int cnt = 0;
    /** Make maxtime */
    int maxtime = 0;
    /** Make a queue */
    int q[10001];
    int head = 0;
    int tail = 0;
    /** Push vertex whose ind equals zero */
    for (i = 0; i < n; i++)
        if (!ind[i])
        {
            q[tail] = i;
            tail++;
        }

    while (head != tail)
    { /** Get vertex u whose ind equals zero */
        int u = q[head];
        head++;
        /** Counting++ */
        cnt++;
        /** Try to update maxtime */
        maxtime = max(maxtime, elist[u]);
        /** Reduce ind */
        for (i = 0; i < m; i++)
        {
            if (a[i].u == u)
            {
                int v = a[i].v;
                int w = a[i].w;
                /** Try to update elist */
                elist[v] = max(elist[v], elist[u] + w);
                ind[v]--;
                /** Push vertex whose ind equals zero */
                if (!ind[v])
                {
                    q[tail] = v;
                    tail++;
                }
            }
        }
    }

    if (cnt == n)
        return maxtime;

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
        a[i] = ed;
        ind[v]++;
    }
    /** Do topsort */
    int maxtime = topsort();
    /** Output */
    if (maxtime != -1)
        printf("%d\n", maxtime);
    else
        printf("Impossible\n");

    return 0;
}
