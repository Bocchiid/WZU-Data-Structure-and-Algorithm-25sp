/** 该解法图的存储为邻接矩阵实现 */

#define INF 0x3f3f3f3f

#include <stdio.h>

int n, m;

char key[101][11];
int a[101][101];
int ind[101];
int order[101];

int topsort()
{
    int i, j;
    int v;
    /** Init order */
    for (i = 0; i < n; i++)
        order[i] = 0;
    /** Make counting */
    int cnt = 0;
    /** Make a queue */
    int q[101];
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
        /** Add order */
        order[cnt] = u;
        /** Counting++ */
        cnt++;
        /** Reduce ind */
        for (v = 0; v < n; v++)
        {
            if (a[u][v] != INF)
            {
                ind[v]--;

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
    int i, j;
    /** Input */
    scanf("%d %d", &n, &m);
    getchar();
    /** Input vertex */
    for (i = 0; i < n; i++)
        scanf("%s", key[i]);
    /** Input edge */
    /** Init a */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = INF;
        }
    }
    /** Init ind */
    for (i = 0; i < n; i++)
        ind[i] = 0;

    for (i = 0; i < m; i++)
    {
        int u, v;

        scanf("%d %d", &u, &v);
        a[u][v] = 0;
        ind[v]++;
    }
    /** Do topsort */
    int flag = topsort();
    /** Output */
    printf("该图拓扑序存在性为 %d\n", flag);
    /** Output order */
    for (i = 0; i < n; i++)
        printf("%s ", key[order[i]]);

    printf("\n");

    return 0;
}
