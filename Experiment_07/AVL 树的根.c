/* 此题和函数6-7考点一致 */
/* 不再过多赘述 */

/* 此题的准备工作较多 */
/* 需先完成 */
/* 1. max
   2. getHeight
   3. LL
   4. RR
   5. LR
   6. RL
   7. createTnode(可选) */

#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    int val;
    struct tnode *left;
    struct tnode *right;
    int height;
} tnode;

tnode *createTnode(int val)
{
    tnode *root = (tnode *)malloc(sizeof(tnode) * 1);
    root->val = val;
    root->left = NULL;
    root->right = NULL;
    root->height = 0;

    return root;
}

int max(int a, int b)
{
    if (a > b)
        return a;

    return b;
}

int getHeight(tnode *root)
{
    if (root)
        return root->height;

    return 0;
}

tnode *LL(tnode *root)
{
    tnode *nroot = root->left;
    root->left = nroot->right;
    nroot->right = root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    nroot->height = max(getHeight(nroot->left), getHeight(nroot->right)) + 1;

    return nroot;
}

tnode *RR(tnode *root)
{
    tnode *nroot = root->right;
    root->right = nroot->left;
    nroot->left = root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    nroot->height = max(getHeight(nroot->left), getHeight(nroot->right)) + 1;

    return nroot;
}

tnode *LR(tnode *root)
{
    root->left = RR(root->left);

    return LL(root);
}

tnode *RL(tnode *root)
{
    root->right = LL(root->right);

    return RR(root);
}

tnode *insert(tnode *root, int val)
{
    if (!root) // if (root == NULL)
        root = createTnode(val);
    else
    {
        if (root->val > val)
        {
            root->left = insert(root->left, val);

            if (getHeight(root->left) - getHeight(root->right) == 2)
            {
                if (root->left->val > val)
                    root = LL(root);
                else
                    root = LR(root);
            }
        }
        else if (root->val < val)
        {
            root->right = insert(root->right, val);

            if (getHeight(root->right) - getHeight(root->left) == 2)
            {
                if (root->right->val < val)
                    root = RR(root);
                else
                    root = RL(root);
            }
        }
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    return root;
}

int main()
{
    int i;
    int n;
    int num;
    tnode *root = NULL;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &num);
        root = insert(root, num);
    }

    printf("%d\n", root->val);

    return 0;
}
