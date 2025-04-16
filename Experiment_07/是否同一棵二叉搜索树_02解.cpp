/* 本题的核心在于如何判断两棵树是否相同 */
/* BST的构建/插入在函数6-1中已经有涉及 */
/* 此处不再过多赘述 */
/* 该解法采用的是判断两棵树是否相同的dfs实现 */

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

tnode *insert(tnode *root, int val)
{
    if (!root) // if (root == nullptr)
    {
        tnode *s = new tnode(val);

        return s;
    }
    /* 类似于二分查找, 递归的查找插入的位置 */
    if (root->val > val)
        root->left = insert(root->left, val);
    else if (root->val < val) /* else */
        root->right = insert(root->right, val);

    return root;
}

bool isSameTree(tnode *p, tnode *q)
{                    /* dfs去层序遍历两棵树, 判断两棵树的每一层是否相同 */
    if (!p && !q)    // if (p == nullptr && q == nullptr)
        return true; /* 1. 若两树均为空树, 则相同 */

    if (p && !q || !p && q) // if (p != nullptr && q == nullptr || p == nullptr && q != nullptr)
        return false;       /* 2. 若一树为空树, 另一树不为空树, 则不相同 */

    queue<tnode *> q1;
    queue<tnode *> q2;

    q1.push(p);
    q2.push(q);

    int i;
    int n, m;

    while (!q1.empty() && !q2.empty())
    {
        n = q1.size();
        m = q2.size();

        if (n != m)
            return false; /* 若两树同一层的结点个数不相同, 则树不同 */
        /* else --> n == m */
        for (i = 0; i < n; i++)
        {
            tnode *t1 = q1.front();
            q1.pop();

            tnode *t2 = q2.front();
            q2.pop();

            if (t1->val != t2->val)
                return false; /* 若同一层的结点不同, 则两树不同 */

            tnode *l1 = t1->left;
            tnode *r1 = t1->right;

            tnode *l2 = t2->left;
            tnode *r2 = t2->right;

            if (l1 && l2) // if (l1 != nullptr && l2 != nullptr)
            {
                if (l1->val != l2->val)
                    return false; /* 若左结点不同, 则树不同 */
            }
            else if (l1 && !l2 || !l1 && l2) // if (l1 != nullptr && l2 == nullptr || l1 == nullptr && l2 != nullptr)
                return false;                /* 若只有一棵树有左结点, 则树不同 */

            if (r1 && r2) // if (r1 != nullptr && r2 != nullptr)
            {
                if (r1->val != r2->val)
                    return false; /* 若右结点不同, 则树不同 */
            }
            else if (r1 && !r2 || !r1 && r2) // if (r1 != nullptr && r2 == nullptr || r1 == nullptr && r2 != nullptr)
                return false;                /* 若只有一棵树有右结点, 则树不同*/

            if (l1)
                q1.push(l1);

            if (r1)
                q1.push(r1);

            if (l2)
                q2.push(l2);

            if (r2)
                q2.push(r2);
        }
    }

    if (q1.empty() && q2.empty())
        return true;
    else
        return false;
}

int main()
{
    int i, j;
    int n, l;
    int num;

    cin >> n;

    while (n != 0)
    {
        cin >> l;

        tnode *p = nullptr;

        for (i = 0; i < n; i++)
        {
            cin >> num;
            p = insert(p, num);
        }

        for (i = 0; i < l; i++)
        {
            tnode *q = nullptr;

            for (j = 0; j < n; j++)
            {
                cin >> num;
                q = insert(q, num);
            }

            if (isSameTree(p, q))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }

        cin >> n;
    }

    return 0;
}
