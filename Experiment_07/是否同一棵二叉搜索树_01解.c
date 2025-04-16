/* 本题的核心在于如何判断两棵树是否相同 */
/* BST的构建/插入在函数6-1中已经有涉及 */
/* 此处不再过多赘述 */
/* 该解法采用的是判断两棵树是否相同的递归实现 */

#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    int val;
    struct tnode *left;
    struct tnode *right;
} tnode;

tnode *createTnode(int val)
{
    tnode *root = (tnode *)malloc(sizeof(tnode) * 1);
    root->val = val;
    root->left = NULL;
    root->right = NULL;

    return root;
}

tnode *insert(tnode *root, int val)
{
    if (!root) // if (root == NULL)
    {
        tnode *s = createTnode(val);

        return s;
    }

    if (root->val > val)
        root->left = insert(root->left, val);
    else if (root->val < val) /* else */
        root->right = insert(root->right, val);

    return root;
}

int isSameTree(tnode *p, tnode *q)
{
    if (!p && !q) // if (p == NULL && q == NULL)
        return 1; /* 1. 若两树均为空树, 则相同 */

    if (p && !q || !p && q) // if (p != NULL && q == NULL || p == NULL && q != NULL)
        return 0;           /* 2. 若一树为空树, 另一树不为空树, 则不相同 */

    if (p->val == q->val) /* 根相同, 两树才有可能相同 */
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right); /* 3. 根相同, 再递归判断左右子树是否相同 */

    return 0; /* 根不同, 两树不可能相同 */
}

int main()
{
    int i, j;
    int n, l;
    int num;

    scanf("%d", &n);

    while (n != 0)
    {
        scanf("%d", &l);
        tnode *p = NULL;

        for (i = 0; i < n; i++)
        {
            scanf("%d", &num);
            p = insert(p, num);
        }

        for (i = 0; i < l; i++)
        {
            tnode *q = NULL;

            for (j = 0; j < n; j++)
            {
                scanf("%d", &num);
                q = insert(q, num);
            }

            if (isSameTree(p, q))
                printf("Yes\n");
            else
                printf("No\n");
        }

        scanf("%d", &n);
    }

    return 0;
}
