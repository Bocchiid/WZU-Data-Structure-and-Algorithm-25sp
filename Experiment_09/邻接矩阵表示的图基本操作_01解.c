/** 01和02解的区别在于是否是函数式实现 */
/** 01解为非函数式(大部分)实现 */

#include <stdio.h>
/** 输出矩阵 */
void print(int a[][1001], int n)
{
    int i, j;

    printf("邻接矩阵为：\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);

        printf("\n");
    }
}

int main()
{
    int i, j;
    int kMaxVertex, no_edge_value;
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
    /** 插入边 */
    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &val);
        a[u][v] = val;
    }

    print(a, n); /** 输出矩阵 */
    printf("顶点数 = %d\n", n); /** 输出结点数 */
    /** 判断边的存在性 */
    for (i = 0; i < 2; i++)
    {
        scanf("%d %d", &u, &v);
        printf("<%d, %d> 的存在性 = %d\n", u, v, a[u][v] != no_edge_value);
    }
    /** 寻找点的第一个邻接点 */
    scanf("%d", &v);

    for (i = 0; i < n; i++)
        if (a[v][i] != no_edge_value)
        {
            printf("顶点%d的第一个邻接点 = %d\n", v, i);
            break;
        }
    /** 删除一条边 */
    scanf("%d %d", &u, &v);
    a[u][v] = no_edge_value;
    printf("<%d, %d> 的存在性 = %d\n", u, v, a[u][v] != no_edge_value);
    /** 删除一个结点 */
    scanf("%d", &v);
    printf("待删除的顶点信息为 %c\n", key[v]);
    key[v] = key[n - 1]; /** 覆盖结点 */
    /** 覆盖边(列) */
    for (i = 0; i < n; i++)
        a[i][v] = a[i][n - 1];
    /** 覆盖边(行) */
    for (j = 0; j < n; j++)
        a[v][j] = a[n - 1][j];
    /** 结点数-1 */
    n--;
    printf("当前顶点数 = %d\n", n); /** 输出结点数 */
    /** 输出边数 */
    int cnt = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] != no_edge_value)
                cnt++;

    printf("当前边数 = %d\n", cnt);
    /** 输出结点 */
    for (i = 0; i < n; i++)
        printf("%c", key[i]);

    printf("\n");
    print(a, n); /** 输出矩阵 */

    return 0;
}
