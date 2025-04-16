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
{                 /* dfs去层序遍历两棵树, 判断两棵树的每一层是否相同 */
    if (!p && !q) // if (p == NULL && q == NULL)
        return 1; /* 1. 若两树均为空树, 则相同 */

    if (p && !q || !p && q) // if (p != NULL && q == NULL || p == NULL && q != NULL)
        return 0;           /* 2. 若一树为空树, 另一树不为空树, 则不相同 */

    tnode *q1[101];
    int head1 = 0;
    int tail1 = 0;

    tnode *q2[101];
    int head2 = 0;
    int tail2 = 0;

    q1[tail1] = p;
    tail1++;
    q2[tail2] = q;
    tail2++;

    int i;
    int n, m;

    while (head1 != tail1 && head2 != tail2)
    {
        n = tail1 - head1;
        m = tail2 - head2;

        if (n != m)
            return 0; /* 若两树同一层的结点个数不相同, 则树不同 */
        /* else --> n == m*/
        for (i = 0; i < n; i++)
        {
            tnode *t1 = q1[head1];
            head1++;

            tnode *t2 = q2[head2];
            head2++;

            if (t1->val != t2->val)
                return 0; /* 若同一层的结点不同, 则两树不同 */

            tnode *l1 = t1->left;
            tnode *r1 = t1->right;

            tnode *l2 = t2->left;
            tnode *r2 = t2->right;

            if (l1 && l2) // if (l1 != NULL && l2 != NULL)
            {
                if (l1->val != l2->val)
                    return 0; /* 若左结点不同, 则树不同 */
            }
            else if (l1 && !l2 || !l1 && l2) // if (l1 != NULL && l2 == NULL || l1 == NULL && l2 != NULL)
                return 0;                    /* 若只有一棵树有左结点, 则树不同 */

            if (r1 && r2) // if (r1 != NULL && r2 != NULL)
            {
                if (r1->val != r2->val)
                    return 0; /* 若右结点不同, 则树不同 */
            }
            else if (r1 && !r2 || !r1 && r2) // if (r1 != NULL && r2 == NULL || r1 == NULL && r2 != NULL)
                return 0;                    /* 若只有一棵树有右结点, 则树不同*/

            if (l1)
            {
                q1[tail1] = l1;
                tail1++;
            }

            if (r1)
            {
                q1[tail1] = r1;
                tail1++;
            }

            if (l2)
            {
                q2[tail2] = l2;
                tail2++;
            }

            if (r2)
            {
                q2[tail2] = r2;
                tail2++;
            }
        }
    }

    return 1;
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
