/* 本题就是在构建二叉树的基础上, 增加了层序遍历bfs和空结点的访问 */
/* 二叉树的一种理解就是在前中后三个特定的时间点, 执行操作*/

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
    if (!root)
        return;

    queue<tnode *> q;
    q.push(root);

    while (!q.empty())
    {
        tnode *t = q.front();
        q.pop();

        if (t)
            cout << t->val << endl;
        else
            cout << "#" << endl;

        if (t)
        {
            q.push(t->left);
            q.push(t->right);
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
    bfs(root);

    return 0;
}
