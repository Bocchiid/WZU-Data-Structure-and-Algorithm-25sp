/* 本题就是在构建二叉树的基础上, 增加了前序遍历 */

#include <iostream>
using namespace std;

struct tnode
{
    int val;
    tnode *left;
    tnode *right;

    tnode(int val) : val(val), left(nullptr), right(nullptr) {}
    tnode(int val, tnode *left, tnode *right) : val(val), left(left), right(right) {}
};

void preorder(tnode *root)
{
    if (root)
    {
        cout << root->val << endl;
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    int val;

    cin >> val;
    tnode *left = new tnode(val);
    cin >> val;
    tnode *right = new tnode(val);
    cin >> val;
    tnode *root = new tnode(val, left, right);
    preorder(root);

    return 0;
}
