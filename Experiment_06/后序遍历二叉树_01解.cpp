/* 本题就是在构建二叉树的基础上, 增加了后序遍历 */
/* 该解法为递归解法 */

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

void postorder(tnode *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->val << endl;
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
    postorder(root);

    return 0;
}
