/** 本题其实就是topsort的实现 + 最早/最晚开始时间的计算 */
/** 由于题目不要求输出拓扑序列, 故不需要order数组 */

/** 该解法图的存储为邻接表实现 */
/** 该解法的邻接表为链表实现 */

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
edge *a[101];
int ind[101];
int elist[101];
/** TopsortL */
edge *rea[101];
int oud[101];
int llist[101];

int topsortE()
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
    { /** Get vertex whose ind equals zero */
        int u = q[head];
        head++;
        /** Counting++ */
        cnt++;
        /** Try to update maxtime */
        maxtime = max(maxtime, elist[u]);
        /** Reduce ind */
        edge *p = a[u]->next;

        while (p)
        {
            int v = p->v;
            int w = p->w;
            /** Try to update elist */
            elist[v] = max(elist[v], elist[u] + w);
            ind[v]--;
            /** Push vertex whose ind equals zero */
            if (!ind[v])
            {
                q[tail] = v;
                tail++;
            }

            p = p->next;
        }
    }

    if (cnt == n)
        return maxtime;

    return -1;
}

int topsortL(int maxtime)
{
    int i, j;
    /** Init llist */
    for (i = 0; i < n; i++)
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
    for (i = 0; i < n; i++)
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
        edge *p = rea[u]->next;

        while (p)
        {
            int v = p->v;
            int w = p->w;
            /** Try to update llist */
            llist[v] = min(llist[v], llist[u] - w);
            oud[v]--;
            /** Push vertex whose oud equals zero */
            if (!oud[v])
            {
                q[tail] = v;
                tail++;
            }

            p = p->next;
        }
    }

    if (cnt == n)
        return mintime;

    return -1;
}

int main()
{
    int i, j;
    /** Input */
    scanf("%d %d", &n, &m);
    /** Init a */
    for (i = 0; i < n; i++)
        a[i] = createEdge(0, 0);
    /** Init ind */
    for (i = 0; i < n; i++)
        ind[i] = 0;
    /** Init rea */
    for (i = 0; i < n; i++)
        rea[i] = createEdge(0, 0);
    /** Inid oud */
    for (i = 0; i < n; i++)
        oud[i] = 0;

    for (i = 0; i < m; i++)
    {
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);

        edge *ed = createEdge(v, w);
        ed->next = a[u]->next;
        a[u]->next = ed;
        ind[v]++;

        ed = createEdge(u, w);
        ed->next = rea[v]->next;
        rea[v]->next = ed;
        oud[u]++;
    }
    /** Do topsortE */
    int maxtime = topsortE();
    /** Check topsortE */
    if (maxtime != -1)
    { /** Do topsortL */
        topsortL(maxtime);
        /** Output critical activities */
        int flag = 0;

        for (i = 0; i < n; i++)
        {
            edge *p = a[i]->next;

            while (p)
            {
                int v = p->v;
                int w = p->w;
                /** Check critical activity */
                if (llist[v] - w == elist[i])
                {
                    flag = 1;

                    printf("<%d, %d>\n", i, v);
                }

                p = p->next;
            }
        }

        printf("关键路径分析结果为 %d\n", flag);
    }
    else
        printf("关键路径分析结果为 0\n");

    return 0;
}
