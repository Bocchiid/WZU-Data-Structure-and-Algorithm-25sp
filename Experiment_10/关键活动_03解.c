/** 本题其实就是topsort的实现 + 最早/最晚开始时间的计算 */
/** 由于题目不要求输出拓扑序列, 故不需要order数组 */

/** 该解法图的存储为邻接矩阵实现 */

#define INF 0x3f3f3f3f

#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;

    return b;
}

int min(int a, int b)
{
    if (a > b)
        return b;

    return a;
}

int n, m;
/** TopsortE */
int a[101][101];
int ind[101];
int elist[101];
/** TopsortL */
int rea[101][101];
int oud[101];
int llist[101];

int topsortE()
{
    int i, j;
    int v;
    /** Init elist */
    for (i = 1; i <= n; i++)
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
    for (i = 1; i <= n; i++)
        if (!ind[i])
        {
            q[tail] = i;
            tail++;
        }

    while (head != tail)
    { /** Get vertex whose ind equals zero */
        int u = q[head];
        head++;
        /** Counting++ */
        cnt++;
        /** Try to update maxtime */
        maxtime = max(maxtime, elist[u]);
        /** Reduce ind */
        for (v = 1; v <= n; v++)
        {
            if (a[u][v] != INF)
            {
                int w = a[u][v];
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

int topsortL(int maxtime)
{
    int i, j;
    int v;
    /** Init llist */
    for (i = 1; i <= n; i++)
        llist[i] = maxtime;
    /** Make counting */
    int cnt = 0;
    /** Make mintime */
    int mintime = 0;
    /** Make a queue */
    int q[10001];
    int head = 0;
    int tail = 0;
    /** Push vertex whose oud equals zero */
    for (i = 1; i <= n; i++)
        if (!oud[i])
        {
            q[tail] = i;
            tail++;
        }

    while (head != tail)
    { /** Get vertex whose oud equals zero */
        int u = q[head];
        head++;
        /** Counting++ */
        cnt++;
        /** Try to update mintime */
        mintime = min(mintime, llist[u]);
        /** Reduce oud */
        for (v = 1; v <= n; v++)
        {
            if (rea[u][v] != INF)
            {
                int w = rea[u][v];
                /** Try to update llist */
                llist[v] = min(llist[v], llist[u] - w);
                oud[v]--;
                /** Push vertex whose oud equals zero */
                if (!oud[v])
                {
                    q[tail] = v;
                    tail++;
                }
            }
        }
    }

    if (cnt == n)
        return mintime;

    return -1;
}

int main()
{
    int i, j;
    int v;
    /** Input */
    scanf("%d %d", &n, &m);
    /** Init a */
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            a[i][j] = INF;
        }
    }
    /** Init ind */
    for (i = 1; i <= n; i++)
        ind[i] = 0;
    /** Init rea */
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            rea[i][j] = INF;
        }
    }
    /** Inid oud */
    for (i = 1; i <= n; i++)
        oud[i] = 0;

    for (i = 0; i < m; i++)
    {
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);

        a[u][v] = w;
        ind[v]++;

        rea[v][u] = w;
        oud[u]++;
    }
    /** Do topsortE */
    int maxtime = topsortE();
    /** Check topsortE */
    if (maxtime != -1)
    { /** Do topsortL */
        topsortL(maxtime);
        /** Output */
        printf("%d\n", maxtime);
        /** Output critical activities */
        for (i = 1; i <= n; i++)
        {
            for (v = n; v >= 1; v--)
            {
                if (a[i][v] != INF)
                {
                    int w = a[i][v];
                    /** Check critical activity */
                    if (llist[v] - w == elist[i])
                        printf("%d->%d\n", i, v);
                }
            }
        }
    }
    else
        printf("0\n");

    return 0;
}
