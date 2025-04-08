/* 本题就是在构建二叉树的基础上, 增加了前序遍历 */
/* 该解法为迭代解法 */

#include <iostream>
#include <stack>
using namespace std;

struct tnode
{
    int val;
    tnode *left;
    tnode *right;

    tnode(int val) : val(val), left(nullptr), right(nullptr) {}
    tnode(int val, tnode *left, tnode *right) : val(val), left(left), right(right) {}
};

void inorder(tnode *root)
{
    if (!root) // if (root == nullptr)
        return;

    stack<tnode *> stk;
    tnode *p = root;

    while (p || !stk.empty())
    {
        if (p)
        {
            stk.push(p);
            p = p->left;
        }
        else
        {
            p = stk.top();
            stk.pop();
            cout << p->val << endl;
            p = p->right;
        }
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
