/** 01和02解的区别在于是否是函数式实现 */
/** 02解为函数式实现 */
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
/** 输出结点 */
void printVertex(char key[], int size)
{
    int i;

    for (i = 0; i < size; i++)
        printf("%c", key[i]);

    printf("\n");
}
/** 插入边 */
void insertEdge(node *a[], int u, int v, int val)
{ /** 头插法构建链表 */
    node *s = createNode(v, val);
    s->next = a[u]->next;
    a[u]->next = s;
}
/** 判断边的存在性 */
int edgeValid(node *a[], int u, int v)
{
    node *p = a[u]->next;

    while (p)
    {
        if (p->v == v)
            return 1;

        p = p->next;
    }

    return 0;
}
/** 获取邻接点 */
int getAdjnode(node *a[], int v)
{ /** 按题目的意思保证一定有, 所以直接输出, 但其实不严谨 */
    return a[v]->next->v;
}
/** 删除结点 */
void deleteVertex(node *a[], char key[], int v, int *size)
{
    int i;

    printf("待删除的顶点信息为 %c\n", key[v]);
    key[v] = key[*size - 1]; /** 覆盖结点 */
    /** 覆盖待删除的结点 */
    a[v] = a[*size - 1];
    /** 结点数-1 */
    (*size)--;
    /** 删除拥有待删除的结点的边 */
    for (i = 0; i < *size; i++)
    {
        node *q = a[i];
        node *p = a[i]->next;

        while (p)
        {
            if (p->v == v)
                q->next = p->next;
            else
                q = p;

            p = p->next;
        }
    }
    /** 修改相应邻接点 */
    for (i = 0; i < *size; i++)
    {
        node *p = a[i]->next;

        while (p)
        {
            if (p->v == *size)
                p->v = v;

            p = p->next;
        }
    }
}
/** 获取结点数 */
int countVertex(int n)
{
    return n;
}
/** 获取边数 */
int countEdge(node *a[], int size)
{
    int i;
    int cnt = 0;

    for (i = 0; i < size; i++)
    {
        node *p = a[i]->next;

        while (p)
        {
            cnt++;
            p = p->next;
        }
    }

    return cnt;
}
/** 输出结点数 */
void printCountVertex(int n)
{
    printf("顶点数 = %d\n", countVertex(n));
}
/** 输出边的存在性 */
void printEdgeValid(node *a[], int u, int v)
{
    printf("<%d, %d> 的存在性 = %d\n", u, v, edgeValid(a, u, v));
}
/** 输出边数 */
void printCountEdge(node *a[], int size)
{
    printf("边数 = %d\n", countEdge(a, size));
}
/** 输出邻接点 */
void printAdjnode(node *a[], int v)
{
    printf("顶点%d的第一个邻接点 = %d\n", v, getAdjnode(a, v));
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
        insertEdge(a, u, v, val);
        /** 根据题目的意思, 本题不会出现重复输入的边, 但题目表述未提及，不严谨 */
    }

    print(a, n);         /** 输出邻接表 */
    printCountVertex(n); /** 输出结点数 */
    /** 判断边的存在性 */
    for (i = 0; i < 2; i++)
    {
        scanf("%d %d", &u, &v);
        printEdgeValid(a, u, v);
    }
    /** 寻找点的邻接点 */
    scanf("%d", &u);
    printAdjnode(a, u);
    /** 删除一个结点 */
    scanf("%d", &u);
    deleteVertex(a, key, u, &n);
    /** 输出结点数 */
    printf("当前");
    printCountVertex(n);
    /** 输出边数 */
    printf("当前");
    printCountEdge(a, n);
    /** 输出结点 */
    printVertex(key, n);
    /** 输出邻接表 */
    print(a, n);

    return 0;
}
