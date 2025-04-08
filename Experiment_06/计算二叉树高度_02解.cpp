/* 本题就是在构建二叉树的基础上, 增加了计算树的深度 */
/* 该解法的思想为遍历 + 维护一个全局变量 */

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

int h;

void getHeight(tnode *root, int deep)
{
    if (!root) // if (root == nullptr)
    {
        h = max(h, deep);
        return;
    }

    deep++;
    getHeight(root->left, deep);
    getHeight(root->right, deep);
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
    h = 0;
    getHeight(root, 0);
    cout << h << endl;

    return 0;
}
