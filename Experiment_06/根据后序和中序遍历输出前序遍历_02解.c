/* 本题的重点在于利用前序和中序不断的寻找根节点 */

#include <stdio.h>
#include <stdlib.h>

int in[101];
int post[101];

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

/* 该函数的参数为左闭右闭 */
tnode *buildTree(int b1, int e1, int b2, int e2)
{ /* 构建根结点 */
    tnode *root = createTnode(post[e2], NULL, NULL);

    int p = b1;
    /* 让p寻找根结点在中序遍历中的位置 */
    while (p != e1 && in[p] != post[e2])
        p++;

    int cnt = p - b1; /* 左子树的结点的个数 */

    if (p != b1) /* 若还有左子树, 则构建左子树 */
        root->left = buildTree(b1, p - 1, b2, b2 + cnt - 1);
    
    if (p != e1) /* 若还有右子树, 则构建右子树 */
        root->right = buildTree(p + 1, e1, b2 + cnt, e2 - 1);

    return root;
}

void preorder(tnode *root)
{
    if (root)
    {
        printf(" %d", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    int i;
    int n;

    scanf("%d", &n);
    getchar();

    for (i = 0; i < n; i++)
        scanf("%d", &post[i]);

    for (i = 0; i < n; i++)
        scanf("%d", &in[i]);

    tnode *root = buildTree(0, n - 1, 0, n - 1);
    printf("Preorder:");
    preorder(root);
    printf("\n");

    return 0;
}
