/** 01和02解的区别在于是否是函数式实现 */
/** 01解为非函数式(大部分)实现 */
/** 01和02解为邻接表的链表实现 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int v;
    int w;
    struct node *next;
} node;

node *createNode(int v, int val)
{
    node *s = (node *)malloc(sizeof(node) * 1);
    s->v = v;
    s->w = val;
    s->next = NULL;

    return s;
}
/** 输出邻接表 */
void print(node *a[], int size)
{
    int i;

    printf("邻接表为：\n");

    for (i = 0; i < size; i++)
    {
        printf("list[%d]", i);
        node *p = a[i]->next;

        while (p)
        {
            printf("->%d:%d", p->v, p->w);
            p = p->next;
        }

        printf("->end\n");
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
        a[i] = createNode(0, 0);

    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &val);
        /** 头插法构建链表 */
        node *s = createNode(v, val);
        s->next = a[u]->next;
        a[u]->next = s;
        /** 根据题目的意思, 本题不会出现重复输入的边, 但题目表述未提及，不严谨 */
    }

    print(a, n);                /** 输出邻接表 */
    printf("顶点数 = %d\n", n); /** 输出结点数 */
    /** 判断边的存在性 */
    for (i = 0; i < 2; i++)
    {
        scanf("%d %d", &u, &v);

        int found = 0;
        node *p = a[u]->next;

        while (p)
        {
            if (p->v == v)
            {
                found = 1;
                break;
            }

            p = p->next;
        }

        printf("<%d, %d> 的存在性 = %d\n", u, v, found);
    }
    /** 寻找点的邻接点 */
    scanf("%d", &u); /** 按题目的意思保证一定有, 所以直接输出, 但其实不严谨 */
    printf("顶点%d的第一个邻接点 = %d\n", u, a[u]->next->v);
    /** 删除一个结点 */
    scanf("%d", &u);
    printf("待删除的顶点信息为 %c\n", key[u]);
    key[u] = key[n - 1]; /** 覆盖结点 */
    /** 覆盖待删除的结点 */
    a[u] = a[n - 1];
    /** 结点数-1 */
    n--;
    /** 删除拥有待删除的结点的边 */
    for (i = 0; i < n; i++)
    {
        node *q = a[i];
        node *p = a[i]->next;

        while (p)
        {
            if (p->v == u)
                q->next = p->next;
            else
                q = p;

            p = p->next;
        }
    }
    /** 修改相应邻接点 */
    for (i = 0; i < n; i++)
    {
        node *p = a[i]->next;

        while (p)
        {
            if (p->v == n)
                p->v = u;

            p = p->next;
        }
    }
    /** 输出结点数 */
    printf("当前顶点数 = %d\n", n);
    /** 输出边数 */
    int cnt = 0;

    for (i = 0; i < n; i++)
    {
        node *p = a[i]->next;

        while (p)
        {
            cnt++;
            p = p->next;
        }
    }

    printf("当前边数 = %d\n", cnt);
    /** 输出结点 */
    for (i = 0; i < n; i++)
        printf("%c", key[i]);

    printf("\n");
    /** 输出邻接表 */
    print(a, n);

    return 0;
}
