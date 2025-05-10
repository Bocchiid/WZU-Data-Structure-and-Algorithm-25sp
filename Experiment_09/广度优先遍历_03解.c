/** 本题重点在于dfs + 计算/输出连通分量 */
/** 对于图的部分不做过多的注解 */

/** 本题请严格使用邻接表存储图 */
/** 该解法为邻接表的链表实现 */

/** 本题较坑的点是要对边去重 */
/** 该解法对去重, 使用的是暴力搜索实现 */

/** 奇数解为全局变量实现 */
/** 偶数解为函数参数实现 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int v;
    struct node *next;
} node;

char key[11];
node *a[11];
int visited[11];

node *createNode(int v)
{
    node *s = (node *)malloc(sizeof(node) * 1);
    s->v = v;
    s->next = NULL;

    return s;
}

int find(int u, int v)
{
    node *p = a[u]->next;

    while (p)
    {
        if (p->v == v)
            return 1;

        p = p->next;
    }

    p = a[v]->next;

    while (p)
    {
        if (p->v == u)
            return 1;

        p = p->next;
    }

    return 0;
}

void bfs(int v)
{
    if (visited[v])
        return;

    int q[1001];
    int head = 0;
    int tail = 0;

    q[tail] = v;
    tail++;

    printf("%c", key[v]);
    visited[v] = 1;

    while (head != tail)
    {
        int t = q[head];
        head++;

        node *p = a[t]->next;

        while (p)
        {
            int vert = p->v;

            if (!visited[vert])
            {
                q[tail] = vert;
                tail++;

                printf("%c", key[vert]);
                visited[vert] = 1;
            }

            p = p->next;
        }
    }
}

int main()
{
    int i, j;
    int kMaxVertex;
    int n, m;
    int u, v, val;
    /** input */
    scanf("%d", &kMaxVertex);
    scanf("%d %d", &n, &m);
    /** input vertex */
    for (i = 0; i < n; i++)
    {
        getchar();
        scanf("%c", &key[i]);
    }
    /** input edge */
    for (i = 0; i < n; i++)
        a[i] = createNode(0);

    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &val);

        if (!find(u, v))
        {
            node *s = createNode(v);
            s->next = a[u]->next;
            a[u]->next = s;

            s = createNode(u);
            s->next = a[v]->next;
            a[v]->next = s;
        }
    }
    /** bfs */
    /** explicitly init visited */
    for (i = 0; i < n; i++)
        visited[i] = 0;

    for (i = 0; i < n; i++)
        if (!visited[i])
        {
            bfs(i);
            printf("\n");
        }

    return 0;
}
