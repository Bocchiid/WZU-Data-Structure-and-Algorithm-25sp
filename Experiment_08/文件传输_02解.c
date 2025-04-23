/* 本题考查并查集的find, union操作 */

/* 01和02解的区别在于是否将数组作为函数形参 */
/* 02解的实现是将数组作为全局变量 */

#include <stdio.h>

int u[10001];

void init(int size)
{
    for (int i = 0; i < size; i++)
        u[i] = -1;
}

int find(int p)
{
    if (u[p] < 0)
        return p;

    u[p] = find(u[p]); /* 路径压缩 */

    return find(u[p]);
}

void unionByRank(int p, int q)
{
    int root1 = find(p);
    int root2 = find(q);

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

int isSameUnion(int p, int q)
{
    int root1 = find(p);
    int root2 = find(q);

    return root1 == root2;
}

int main()
{
    int i;
    int n;

    scanf("%d", &n);
    init(n);

    char op;
    scanf("%c", &op);

    while (op != 'S')
    {
        int a, b;

        scanf("%d %d", &a, &b);

        if (op == 'I')
            unionByRank(a - 1, b - 1);
        else if (op == 'C')
        {
            if (isSameUnion(a - 1, b - 1))
                printf("yes\n");
            else
                printf("no\n");
        }

        scanf("%c", &op);
    }

    int cnt = 0;

    for (i = 0; i < n; i++)
        if (u[i] < 0)
            cnt++;

    if (cnt == 1)
        printf("The network is connected.\n");
    else
        printf("There are %d components.\n", cnt);

    return 0;
}
