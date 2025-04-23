/* 本题考查并查集的find, union操作 */

/* 01和02解的区别在于是否将数组作为函数形参 */
/* 01解的实现是将数组作为函数形参 */
/* 该解只是将下标改为从1开始 */

#include <stdio.h>

void init(int u[], int size)
{
    for (int i = 1; i <= size; i++)
        u[i] = -1;
}

int find(int u[], int p)
{
    if (u[p] < 0)
        return p;

    u[p] = find(u, u[p]); /* 路径压缩 */

    return find(u, u[p]);
}

void unionByRank(int u[], int p, int q)
{
    int root1 = find(u, p);
    int root2 = find(u, q);

    if (root1 != root2)
    {
        if (u[root1] < u[root2])
        {
            u[root1] += u[root2];
            u[root2] = root1;
        }
        else
        {
            u[root2] += u[root1];
            u[root1] = root2;
        }
    }
}

int isSameUnion(int u[], int p, int q)
{
    int root1 = find(u, p);
    int root2 = find(u, q);

    return root1 == root2;
}

int main()
{
    int i;
    int n;

    scanf("%d", &n);
    int u[10001] = {0};
    init(u, n);

    char op;
    scanf("%c", &op);

    while (op != 'S')
    {
        int a, b;

        scanf("%d %d", &a, &b);

        if (op == 'I')
            unionByRank(u, a, b);
        else if (op == 'C')
        {
            if (isSameUnion(u, a, b))
                printf("yes\n");
            else
                printf("no\n");
        }

        scanf("%c", &op);
    }

    int cnt = 0;

    for (i = 1; i <= n; i++)
        if (u[i] < 0)
            cnt++;

    if (cnt == 1)
        printf("The network is connected.\n");
    else
        printf("There are %d components.\n", cnt);

    return 0;
}
