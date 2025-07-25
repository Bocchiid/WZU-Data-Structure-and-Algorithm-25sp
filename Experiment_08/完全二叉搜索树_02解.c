/* 本题的思路为先构树, 再填值 */
/* 利用BST中序遍历得到的序列是递增序列的特点 */
/* 故该完全二叉树可由中序遍历得到 */
/* 该解法是利用顺序表实现完全二叉树 */

/* 01和02解的区别在于是否将数组作为函数形参 */
/* 02解的实现是将数组作为全局变量 */

#include <stdio.h>
#include <stdlib.h>

int n;
int cnt;
int a[1001];
int tree[1001];

int cmp(void *a, void *b)
{
    return (*(int *)a) > (*(int *)b);
}

void inorder(int root)
{
    if (root <= n)
    {
        inorder(root * 2);

        tree[root] = a[cnt];
        cnt++;

        inorder(root * 2 + 1);
    }
}

int main()
{
    int i, j;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    qsort(a, n, sizeof(int), cmp);

    cnt = 0;
    inorder(1);

    for (i = 1; i <= n; i++)
    {
        if (i != 1)
            printf(" ");

        printf("%d", tree[i]);
    }

    printf("\n");

    return 0;
}
