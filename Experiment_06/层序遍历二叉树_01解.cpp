/* 本题就是在构建二叉树的基础上, 增加了层序遍历(BFS) */

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

void bfs(tnode *root)
{
    if (!root) // if (root == nullptr)
        return;

    queue<tnode *> q;

    q.push(root);

    while (!q.empty())
    {
        tnode *t = q.front();

        if (t->left)
            q.push(t->left);

        if (t->right)
            q.push(t->right);

        cout << t->val << endl;
        q.pop();
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
    bfs(root);

    return 0;
}
