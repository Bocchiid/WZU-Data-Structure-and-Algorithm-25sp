/* 该解法的思路从前序遍历入手 */
/* 关键在于如何知道访问结点时的时间节点 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tnode
{
    char val[101];
    struct tnode *left;
    struct tnode *right;
} tnode;

int n;
int cnt; /* cnt用于记录访问时的当前时间节点 */

tnode *createTnode(char val[], tnode *left, tnode *right)
{
    tnode *root = (tnode *)malloc(sizeof(tnode) * 1);
    strcpy(root->val, val);
    root->left = left;
    root->right = right;

    return root;
}

tnode *buildTree(char a[][101])
{ /* 模拟一遍二叉树前序遍历的递归实现 */
    if (cnt >= n || strcmp(a[cnt], "#") == 0)
    {
        cnt++;
        return NULL;
    }

    tnode *root = createTnode(a[cnt], NULL, NULL);
    cnt++;

    root->left = buildTree(a);
    root->right = buildTree(a);

    return root;
}

void preorder(tnode *root)
{
    if (root)
    {
        printf("%s\n", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    int i;

    scanf("%d", &n);

    char a[50][101];

    for (i = 0; i < n; i++)
        scanf("%s", a[i]);

    cnt = 0;
    tnode *root = buildTree(a);
    preorder(root);

    return 0;
}
