/* 本题就是在构建二叉树的基础上, 增加了中序遍历 */
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

void inorder(tnode *root)
{
    if (!root) // if (root == NULL)
        return;

    tnode *stk[101];
    int top = -1;

    tnode *p = root;

    while (p || top != -1)
    {
        if (p)
        {
            top++;
            stk[top] = p;
            p = p->left;
        }
        else
        {
            p = stk[top];
            top--;
            printf("%d\n", p->val);
            p = p->right;
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
    inorder(root);

    return 0;
}
