/* 本题就是在构建二叉树的基础上, 增加了层序遍历(BFS) */

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

void bfs(tnode *root)
{
    if (!root) // if (root == NULL)
        return;

    tnode *q[1001];
    int head = 0;
    int tail = 0;

    q[tail] = root;
    tail++;

    while (head != tail)
    {
        tnode *t = q[head];

        if (t->left)
        {
            q[tail] = t->left;
            tail++;
        }

        if (t->right)
        {
            q[tail] = t->right;
            tail++;
        }

        printf("%d", t->val);
        head++;
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
    bfs(root);

    return 0;
}
