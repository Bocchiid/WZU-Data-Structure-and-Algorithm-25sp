/* 本题就是在构建二叉树的基础上, 增加了计算树的深度 */

#include <iostream>
#include <queue>
using namespace std;

struct tnode
{
    int val;
    tnode *left;
    tnode *right;

    tnode(int val) : val(val), left(nullptr), right(nullptr) {}
    tnode(int val, tnode *left, tnode *right) : val(val), left(left), right(right) {}
};

int getHeight(tnode *root)
{
    if (!root) // if (root == nullptr)
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
    int val;

    cin >> val;
    tnode *left = new tnode(val);
    cin >> val;
    tnode *right = new tnode(val);
    cin >> val;
    tnode *root = new tnode(val, left, right);
    cout << getHeight(root) << endl;

    return 0;
}
