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

void preorder(tnode *root)
{
    if (!root) // if (root == nullptr)
        return;

    stack<tnode *> stk;
    stk.push(root);

    while (!stk.empty())
    {
        tnode *t = stk.top();
        stk.pop();

        cout << t->val << endl;
        
        if (t->right)
            stk.push(t->right);

        if (t->left)
            stk.push(t->left);
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
