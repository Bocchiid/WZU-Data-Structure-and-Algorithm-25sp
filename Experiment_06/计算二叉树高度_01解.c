/* 本题就是在构建二叉树的基础上, 增加了计算树的深度 */

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

int getHeight(tnode *root)
{
    if (!root) // if (root == NULL)
        return 0;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    int maxHeight = leftHeight;

    if (rightHeight > maxHeight) // if (rightHeight > leftHeight)
        maxHeight = rightHeight;

    return maxHeight + 1;
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
    printf("%d\n", getHeight(root));

    return 0;
}
