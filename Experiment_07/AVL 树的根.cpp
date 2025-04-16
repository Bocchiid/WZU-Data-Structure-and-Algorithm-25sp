/* 此题和函数6-7考点一致 */
/* 不再过多赘述 */

/* 此题的准备工作较多 */
/* 需先完成 */
/* 1. getHeight
   2. LL
   3. RR
   4. LR
   5. RL
   6. createTnode(可选) */

#include <iostream>
using namespace std;

struct tnode
{
    int val;
    tnode *left;
    tnode *right;
    int height;

    tnode(int val) : val(val), left(nullptr), right(nullptr), height(0) {}
    tnode(int val, tnode *left, tnode *right) : val(val), left(left), right(right), height(0) {}
};

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
    if (!root)
        root = new tnode(val);
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
    tnode *root = nullptr;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> num;
        root = insert(root, num);
    }

    cout << root->val << endl;

    return 0;
}
