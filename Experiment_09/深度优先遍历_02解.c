/** 本题重点在于dfs + 计算/输出连通分量 */
/** 对于图的部分不做过多的注解 */

/** 本题请严格使用邻接表存储图 */
/** 该解法为邻接表的链表实现 */

/** 本题较坑的点是要对边去重 */
/** 该解法对去重, 使用的是二维数组实现 */

/** 奇数解为全局变量实现 */
/** 偶数解为函数参数实现 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int v;
    struct node *next;
} node;

int valid[11][11];

node *createNode(int v)
{
    node *s = (node *)malloc(sizeof(node) * 1);
    s->v = v;
    s->next = NULL;

    return s;
}

void dfs(int v, node *a[], char key[], int visited[])
{
    if (visited[v])
        return;

    printf("%c", key[v]);
    visited[v] = 1;

    node *p = a[v]->next;

    while (p)
    {
        dfs(p->v, a, key, visited);
        p = p->next;
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
    char key[11];

    for (i = 0; i < n; i++)
    {
        getchar();
        scanf("%c", &key[i]);
    }
    /** input edge */
    node *a[11];

    for (i = 0; i < n; i++)
        a[i] = createNode(0);
    /** explicitly init valid */
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            valid[i][j] = 0;

    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &val);

        if (!valid[u][v] && !valid[v][u])
        {
            node *s = createNode(v);
            s->next = a[u]->next;
            a[u]->next = s;

            s = createNode(u);
            s->next = a[v]->next;
            a[v]->next = s;

            valid[u][v] = 1;
            valid[v][u] = 1;
        }
    }
    /** bfs */
    int visited[11];
    /** explicitly init visited */
    for (i = 0; i < n; i++)
        visited[i] = 0;

    for (i = 0; i < n; i++)
        if (!visited[i])
        {
            dfs(i, a, key, visited);
            printf("\n");
        }

    return 0;
}
