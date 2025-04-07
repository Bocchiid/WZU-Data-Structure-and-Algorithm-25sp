/* 该解法中, 构建二叉树和寻找二叉树根的位置和 题目: 列出叶节点 一致 */
/* 本题重点在于如何判断两棵树是否同构 */
/* 注重对同构情况的分类 */
/* 1. 二树皆空, 同构 */
/* 2. 一树为空, 不同构 */
/* 3. 两树根得相同才能同构 */
/* 4. 两树相同, 同构 */
/* 5. 两树交换后相同, 同构 */
/* 6. else 不同构 */

#include <stdio.h>

typedef struct tnode
{
    char val;
    int left;
    int right;
} tnode;

int isomorphic(int root1, int root2, tnode a[], tnode b[])
{ /* 1. 两树都为空树 */
    if (root1 == -1 && root2 == -1)
        return 1;
    /* 2. 一树为空树 */
    if (root1 == -1 && root2 != -1 || root1 != -1 && root2 == -1)
        return 0;
    /* 3. 树根得相同 */
    if (a[root1].val == b[root2].val)
    { /* 4. 不交换两树相同, 即左右子树都相同 */
        if (isomorphic(a[root1].left, b[root2].left, a, b) && 
            isomorphic(a[root1].right, b[root2].right, a, b))
            return 1;
        /* 5. 交换两树相同, 即左和右相同, 右和左相同 */
        if (isomorphic(a[root1].left, b[root2].right, a, b) && 
            isomorphic(a[root1].right, b[root2].left, a, b))
            return 1;
        /* 都不满足的话, 则不同构 */
        return 0;
    }
    else
        return 0;
}

int main()
{
    int i;
    int n, m;

    char s[101];
    char val;
    char left, right;

    scanf("%d", &n);
    getchar();

    tnode a[101];
    int check1[101] = {0};

    for (i = 0; i < n; i++)
    {
        gets(s);

        val = s[0];
        left = s[2];
        right = s[4];

        a[i].val = val;

        if (left != '-')
        {
            a[i].left = left - '0';
            check1[a[i].left] = 1;
        }
        else
            a[i].left = -1;

        if (right != '-')
        {
            a[i].right = right - '0';
            check1[a[i].right] = 1;
        }
        else
            a[i].right = -1;
    }

    scanf("%d", &m);
    getchar();

    if (n != m)
    {
        printf("No\n");

        return 0;
    }

    tnode b[101];
    int check2[101] = {0};

    for (i = 0; i < m; i++)
    {
        gets(s);

        val = s[0];
        left = s[2];
        right = s[4];

        b[i].val = val;

        if (left != '-')
        {
            b[i].left = left - '0';
            check2[b[i].left] = 1;
        }
        else
            b[i].left = -1;

        if (right != '-')
        {
            b[i].right = right - '0';
            check2[b[i].right] = 1;
        }
        else
            b[i].right = -1;
    }

    int root1 = -1;
    int root2 = -1;

    for (i = 0; i < n; i++)
        if (!check1[i])
        {
            root1 = i;
            break;
        }

    for (i = 0; i < m; i++)
        if (!check2[i])
        {
            root2 = i;
            break;
        }

    if (isomorphic(root1, root2, a, b))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
