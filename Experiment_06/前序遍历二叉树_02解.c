/* 本题就是在构建二叉树的基础上, 增加了前序遍历 */
/* 该解法为迭代解法 */

#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    int val;
    struct tnode *left;
    struct tnode *right;
} tnode;

tnode *createTnode(int val, tnode *left, tnode *right)
{
    tnode *s = (tnode *)malloc(sizeof(tnode) * 1);
    s->val = val;
    s->left = left;
    s->right = right;

    return s;
}

void preorder(tnode *root)
{
    if (!root) // if (root == NULL)
        return;

    tnode *stk[101];
    int top = -1;

    top++;
    stk[top] = root;

    while (top != -1)
    {
        tnode *t = stk[top];
        top--;

        printf("%d\n", t->val);

        if (t->right)
        {
            top++;
            stk[top] = t->right;
        }

        if (t->left)
        {
            top++;
            stk[top] = t->left;
        }
    }
}

int main()
{
    int val;

    scanf("%d", &val);
    tnode *left = createTnode(val, NULL, NULL);
    scanf("%d", &val);
    tnode *right = createTnode(val, NULL, NULL);
    scanf("%d", &val);
    tnode *root = createTnode(val, left, right);
    preorder(root);

    return 0;
}
