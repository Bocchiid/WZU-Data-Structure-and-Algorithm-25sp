/* 本题就是在构建二叉树的基础上, 增加了中序遍历 */

#include <iostream>
using namespace std;

struct tnode
{
    int val;
    tnode *left;
    tnode *right;

    tnode(int val) : val(val), left(left), right(right) {}
    tnode(int val, tnode *left, tnode *right) : val(val), left(left), right(right) {}
};

void inorder(tnode *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->val << endl;
        inorder(root->right);
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
    inorder(root);

    return 0;
}
