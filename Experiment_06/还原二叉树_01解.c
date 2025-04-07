/* 本题的重点在于利用前序和中序不断的寻找根节点 */

#include <stdio.h>
#include <stdlib.h>

char pre[101];
char in[101];

typedef struct tnode
{
    char val;
    struct tnode *left;
    struct tnode *right;
} tnode;

tnode *createTnode(char val, tnode *left, tnode *right)
{
    tnode *s = (tnode *)malloc(sizeof(tnode) * 1);
    s->val = val;
    s->left = left;
    s->right = right;

    return s;
}

/* 该函数的参数为左闭右开 */
tnode *buildTree(int b1, int e1, int b2, int e2)
{ /* 空树的构建 */
    if (e1 == 0 && e2 == 0)
        return NULL;
    /* 构建根结点 */
    tnode *root = createTnode(pre[b1], NULL, NULL);

    int p = b2;
    /* 让p寻找根结点在中序遍历中的位置 */
    while (p < e2 && in[p] != pre[b1])
        p++;

    int cnt = p - b2; /* 左子树的结点的个数 */

    if (p != b2) /* 若还有左子树, 则构建左子树 */
        root->left = buildTree(b1 + 1, b1 + 1 + cnt, b2, p);
    if (p != e2 - 1) /* 若还有右子树, 则构建右子树 */
        root->right = buildTree(b1 + 1 + cnt, e1, p + 1, e2);

    return root;
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
    int i;
    int n;

    scanf("%d", &n);
    getchar();

    for (i = 0; i < n; i++)
        scanf("%c", &pre[i]);

    getchar();

    for (i = 0; i < n; i++)
        scanf("%c", &in[i]);

    tnode *root = buildTree(0, n, 0, n);
    printf("%d\n", getHeight(root));

    return 0;
}
