/** 该解法图的存储为邻接表实现 */
/** 该解法的邻接表为链表实现 */

#include <stdio.h>
#include <stdlib.h>

typedef struct edge
{
    int v;
    struct edge *next;
} edge;

edge *createEdge(int v)
{
    edge *ed = (edge *)malloc(sizeof(edge) * 1);
    ed->v = v;
    ed->next = NULL;

    return ed;
}

int n, m;

char key[101][11];
edge *a[10001];
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
        edge *p = a[u]->next;

        while (p)
        {
            int v = p->v;

            ind[v]--;
            /** push items whose ind equals zero */
            if (!ind[v])
            {
                q[tail] = v;
                tail++;
            }

            p = p->next;
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
    /** init a array */
    for (i = 0; i < n; i++)
        a[i] = createEdge(0);
    /** init ind */
    for (i = 0; i < n; i++)
        ind[i] = 0;

    for (i = 0; i < m; i++)
    {
        int u, v;

        scanf("%d %d", &u, &v);
        edge *ed = createEdge(v);

        ed->next = a[u]->next;
        a[u]->next = ed;

        ind[v]++;
    }
    /** topsort */
    int flag = topsort();

    printf("该图拓扑序存在性为 %d\n", flag);
    /** output order */
    for (i = 0; i < n; i++)
        printf("%s ", key[order[i]]);

    printf("\n");

    return 0;
}
