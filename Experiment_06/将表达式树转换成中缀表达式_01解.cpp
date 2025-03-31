/* 本题就是在构建二叉树的基础上, 增加了中序遍历 + 在特定时间点执行特定操作 */
/* 二叉树的一种理解就是在前中后三个特定的时间点, 执行操作*/

#include <iostream>
using namespace std;

struct tnode
{
    string val;
    tnode *left;
    tnode *right;

    tnode(string val) : val(val), left(nullptr), right(nullptr) {}
    tnode(string val, tnode *left, tnode *right) : val(val), left(left), right(right) {}
};

void inorder(tnode *root, int deep)
{
    if (root)
    {
        if (deep > 1)
            cout << "(";

        inorder(root->left, deep + 1);
        cout << root->val;
        inorder(root->right, deep + 1);

        if (deep > 1)
            cout << ")";
    }
}

int main()
{
    string val;

    cin >> val;
    tnode *left = new tnode(val);
    cin >> val;
    tnode *right = new tnode(val);
    cin >> val;
    tnode *root = new tnode(val, left, right);
    inorder(root, 1);
    cout << endl;

    return 0;
}
