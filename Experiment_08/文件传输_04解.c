/* 本题考查并查集的find, union操作 */

/* 03和04解和01和02解的区别在于数组是否从1开始计数 */
/* 03和04解的区别在于是否将数组作为函数形参 */
/* 04解的实现是将数组作为全局变量 */

#include <stdio.h>

int a[10001];

void init(int size)
{
    for (int i = 0; i < size; i++)
        a[i] = -1;
}

int find(int p)
{
    if (a[p] < 0)
        return p;

    a[p] = find(a[p]); /* 路径压缩 */

    return find(a[p]);
}
/* 按秩(rank)合并 */
void unionByRank(int p, int q)
{ /* 此处以树的元素个数为秩 */
    int root1 = find(p);
    int root2 = find(q);

    if (root1 != root2)
    {
        if (a[root1] < a[root2])
        {
            a[root1] += a[root2];
            a[root2] = root1;
        }
        else
        {
            a[root2] += a[root1];
            a[root1] = root2;
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
    int i, j;
    int n;

    scanf("%d", &n);
    init(n);

    char op;
    scanf("%c", &op);

    int c1, c2;

    while (op != 'S')
    {
        scanf("%d %d", &c1, &c2);

        if (op == 'I')
            unionByRank(c1 - 1, c2 - 1);
        else if (op == 'C')
            if (isSameUnion(c1 - 1, c2 - 1))
                printf("yes\n");
            else
                printf("no\n");
        
        scanf("%c", &op);
    }

    int cnt = 0;

    for (i = 0; i < n; i++)
        if (a[i] < 0)
            cnt++;

    if (cnt == 1)
        printf("The network is connected.\n");
    else
        printf("There are %d components.\n", cnt);

    return 0;
}
