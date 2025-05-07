/** 01和02解的区别在于是否是函数式实现 */
/** 02解为函数式实现 */

#include <stdio.h>

int kMaxVertex, no_edge_value;

/** 输出矩阵 */
void print(int a[][1001], int size)
{
    int i, j;

    printf("邻接矩阵为：\n");

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
            printf("%d ", a[i][j]);

        printf("\n");
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
void insertEdge(int a[][1001], int u, int v, int val)
{
    a[u][v] = val;
}
/** 删除边 */
void deleteEdge(int a[][1001], int u, int v)
{
    a[u][v] = no_edge_value;
}
/** 判断边的存在性 */
int edgeValid(int a[][1001], int u, int v)
{
    return a[u][v] != no_edge_value;
}
/** 获取邻接点 */
int getAdjnode(int a[][1001], int v, int n)
{
    int i;

    for (i = 0; i < n; i++)
        if (a[v][i] != no_edge_value)
            return i;
}
/** 删除结点 */
void deleteVertex(int a[][1001], char key[], int v, int *n)
{
    int i, j;

    printf("待删除的顶点信息为 %c\n", key[v]);
    key[v] = key[*n - 1]; /** 覆盖结点 */
    /** 覆盖边(列) */
    for (i = 0; i < *n; i++)
        a[i][v] = a[i][*n - 1];
    /** 覆盖边(行) */
    for (j = 0; j < *n; j++)
        a[v][j] = a[*n - 1][j];
    /** 结点数-1 */
    (*n)--;
}
/** 获取结点数 */
int countVertex(int n)
{
    return n;
}
/** 获取边数 */
int countEdge(int a[][1001], int n)
{
    int i, j;
    int cnt = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] != no_edge_value)
                cnt++;

    return cnt;
}
/** 输出结点数 */
void printCountVertex(int n)
{
    printf("顶点数 = %d\n", countVertex(n));
}
/** 输出边的存在性 */
void printEdgeValid(int a[][1001], int u, int v)
{
    printf("<%d, %d> 的存在性 = %d\n", u, v, edgeValid(a, u, v));
}
/** 输出边数 */
void printCountEdge(int a[][1001], int n)
{
    printf("边数 = %d\n", countEdge(a, n));
}
/** 输出邻接点 */
void printAdjnode(int a[][1001], int v, int n)
{
    printf("顶点%d的第一个邻接点 = %d\n", v, getAdjnode(a, v, n));
}

int main()
{
    int i, j;
    int n, m;
    int u, v, val;
    /** input */
    scanf("%d %d", &kMaxVertex, &no_edge_value);
    scanf("%d %d", &n, &m);
    getchar();

    char key[1001];

    for (i = 0; i < n; i++)
        scanf("%c ", &key[i]);
    /** 初始化矩阵 */
    int a[1001][1001];

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            a[i][j] = no_edge_value;

    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &val);
        insertEdge(a, u, v, val);
    }

    print(a, n); /** 输出矩阵 */
    printCountVertex(n); /** 输出结点数 */
    /** 输出边的存在性 */
    for (i = 0; i < 2; i++)
    {
        scanf("%d %d", &u, &v);
        printEdgeValid(a, u, v);
    }
    /** 输出第一个邻接点 */
    scanf("%d", &v);
    printAdjnode(a, v, n);
    /** 删除边 */
    scanf("%d %d", &u, &v);
    deleteEdge(a, u, v);
    printEdgeValid(a, u, v);
    /** 删除结点 */
    scanf("%d", &v);
    deleteVertex(a, key, v, &n);
    /** 输出顶点数 */
    printf("当前");
    printCountVertex(n);
    /** 输出边数 */
    printf("当前");
    printCountEdge(a, n);
    /** 输出结点 */
    printVertex(key, n);
    /** 输出矩阵 */
    print(a, n);

    return 0;
}
