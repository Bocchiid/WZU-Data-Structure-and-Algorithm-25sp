/* 本题就是在构建二叉树的基础上, 增加了计算树的深度 */
/* 该解法为层序遍历bfs */

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
    int h = 0;

    if (!root) // if (root == NULL)
        return h;

    tnode *q[101];
    int head = 0;
    int tail = 0;

    q[tail] = root;
    tail++;

    while (head != tail)
    {
        int n = tail - head;
        h++;

        for (int i = 0; i < n; i++)
        {
            tnode *t = q[head];
            head++;

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
        }
    }

    return h;
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
