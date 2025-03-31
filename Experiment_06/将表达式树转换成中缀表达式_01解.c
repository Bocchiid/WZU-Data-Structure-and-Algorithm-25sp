/* 本题就是在构建二叉树的基础上, 增加了中序遍历 + 在特定时间点执行特定操作 */
/* 二叉树的一种理解就是在前中后三个特定的时间点, 执行操作*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tnode
{
    char val[101];
    struct tnode *left;
    struct tnode *right;
} tnode;

tnode* createTnode(char val[], tnode *left, tnode *right)
{
    tnode *s = (tnode *)malloc(sizeof(tnode) * 1);
    strcpy(s->val, val);
    s->left = left;
    s->right = right;

    return s;
}

void inorder(tnode *root, int deep)
{
    if (root)
    {
        if (deep > 1)
            printf("(");

        inorder(root->left, deep + 1);
        printf("%s", root->val);
        inorder(root->right, deep + 1);

        if (deep > 1)
            printf(")");
    }
}

int main()
{
    char val[101];

    scanf("%s", val);
    tnode *left = createTnode(val, NULL, NULL);
    scanf("%s", val);
    tnode *right = createTnode(val, NULL, NULL);
    scanf("%s", val);
    tnode *root = createTnode(val, left, right);
    inorder(root, 1);
    printf("\n");

    return 0;
}
