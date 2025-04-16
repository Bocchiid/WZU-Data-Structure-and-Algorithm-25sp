/* 本题的核心在于如何判断两棵树是否相同 */
/* BST的构建/插入在函数6-1中已经有涉及 */
/* 此处不再过多赘述 */
/* 该解法采用的是判断两棵树是否相同的递归实现 */

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
{
    if (!p && !q)    // if (p == nullptr && q == nullptr)
        return true; /* 1. 若两树均为空树, 则相同 */

    if (p && !q || !p && q) // if (p != nullptr && q == nullptr || p == nullptr && q != nullptr)
        return false;       /* 2. 若一树为空树, 另一树不为空树, 则不相同 */

    if (p->val == q->val) /* 根相同, 两树才有可能相同 */
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right); /* 3. 根相同, 再递归判断左右子树是否相同 */

    return false; /* 根不同, 两树不可能相同 */
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
