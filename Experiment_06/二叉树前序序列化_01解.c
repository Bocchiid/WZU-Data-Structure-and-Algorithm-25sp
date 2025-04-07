/* 本题就是在构建二叉树的基础上, 增加了前序遍历和空结点的访问 */
/* 二叉树的一种理解就是在前中后三个特定的时间点, 执行操作*/

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
    if (root)
    {
        printf("%d\n", root->val);
        preorder(root->left);
        preorder(root->right);
    }
    else
        printf("#\n");
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
