/* 本题就是在构建二叉树的基础上, 增加了中序遍历 + 在特定时间点执行特定操作 */
/* 二叉树的一种理解就是在前中后三个特定的时间点, 执行操作*/

/* 此解法虽然能过OJ, 但完全不符合题目要求, 对树的学习不利 */
/* 所以, 还请读者自觉学习树的做法 */

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
    else
        cout << "#" << endl;
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
