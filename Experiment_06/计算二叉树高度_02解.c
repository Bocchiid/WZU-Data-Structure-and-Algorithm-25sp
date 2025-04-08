/* 本题就是在构建二叉树的基础上, 增加了计算树的深度 */
/* 该解法的思想为遍历 + 维护一个全局变量 */

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

int h;

void getHeight(tnode *root, int deep)
{
    if (!root) // if (root == NULL)
    {
        if (deep > h)
            h = deep;

        return;
    }

    deep++;
    getHeight(root->left, deep);
    getHeight(root->right, deep);
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
    h = 0;
    getHeight(root, 0);
    printf("%d\n", h);

    return 0;
}
