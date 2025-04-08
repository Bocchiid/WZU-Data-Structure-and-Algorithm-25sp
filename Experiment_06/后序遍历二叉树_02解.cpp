/* 本题就是在构建二叉树的基础上, 增加了后序遍历 */
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

void postorder(tnode *root)
{
    if (!root) // if (root == nullptr)
        return;

    stack<tnode *> stk;
    stk.push(root);

    stack<int> ans;

    while (!stk.empty())
    {
        tnode *t = stk.top();
        stk.pop();

        ans.push(t->val);

        if (t->left)
            stk.push(t->left);

        if (t->right)
            stk.push(t->right);
    }

    while (!ans.empty())
    {
        int val = ans.top();
        ans.pop();
        cout << val << endl;
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
