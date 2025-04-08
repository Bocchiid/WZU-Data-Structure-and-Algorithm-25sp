/* 本题就是在构建二叉树的基础上, 增加了计算树的深度 */
/* 该解法为层序遍历bfs */

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
    int h = 0;

    if (!root) // if (root == nullptr)
        return h;

    queue<tnode *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        h++;

        for (int i = 0; i < n; i++)
        {
            tnode *t = q.front();
            q.pop();

            if (t->left)
                q.push(t->left);

            if (t->right)
                q.push(t->right);
        }
    }

    return h;
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
