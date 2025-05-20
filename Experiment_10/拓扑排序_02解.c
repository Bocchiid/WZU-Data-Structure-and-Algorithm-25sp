/** 该解法图的存储为直接存储边实现 */

#include <stdio.h>

typedef struct edge
{
    int u;
    int v;
} edge;

int n, m;

char key[101][11];
edge a[10001];
int ind[101];
int order[101];

int topsort()
{
    int i, j;
    /** init order */
    for (i = 0; i < n; i++)
        order[i] = 0;
    /** make counting */
    int cnt = 0;
    /** make a queue */
    int q[101];
    int head = 0;
    int tail = 0;
    /** push items whose ind equals zero */
    for (i = 0; i < n; i++)
        if (!ind[i])
        {
            q[tail] = i;
            tail++;
        }

    while (head != tail)
    { /** pop item from queue */
        int u = q[head];
        head++;
        /** add order */
        order[cnt] = u;
        /** counting++ */
        cnt++;
        /** reduce ind */
        for (i = 0; i < m; i++)
        { /** find edge with beginning point u */
            if (a[i].u == u)
            {
                int v = a[i].v;

                ind[v]--;
                /** push items whose ind equals zero */
                if (!ind[v])
                {
                    q[tail] = v;
                    tail++;
                }
            }
        }
    }

    if (cnt == n)
        return 1;

    return 0;
}

int main()
{
    int i, j, k;
    /** input */
    scanf("%d %d", &n, &m);
    getchar();
    /** input vertex */
    for (i = 0; i < n; i++)
        scanf("%s", key[i]);
    /** input edge */
    /** init ind */
    for (i = 0; i < n; i++)
        ind[i] = 0;

    for (i = 0; i < m; i++)
    {
        int u, v;

        scanf("%d %d", &u, &v);
        a[i].u = u;
        a[i].v = v;

        ind[v]++;
    }
    /** topsort */
    int flag = topsort();

    printf("该图拓扑序存在性为 %d\n", flag);
    /** output order */
    for (i = 0; i < n; i++)
        printf("%s ", key[order[i]]);

    return 0;
}
