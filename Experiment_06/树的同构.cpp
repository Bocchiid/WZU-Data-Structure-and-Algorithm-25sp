/**/

/* 此解法虽然能过OJ, 但完全不符合题目要求, 对树的学习不利 */
/* 所以, 还请读者自觉学习树的做法 */

#include <iostream>
#include <vector>
using namespace std;

struct tnode
{
    char val;
    int left;
    int right;
};

bool isomorphic(int root1, int root2, vector<tnode> a, vector<tnode> b)
{ /* 1. 两树都为空树 */
    if (root1 == -1 && root2 == -1)
        return true;
    /* 2. 一树为空树 */
    if (root1 != -1 && root2 == -1 || root1 == -1 && root2 != -1)
        return false;
    /* 3. 树根得相同 */
    if (a[root1].val == b[root2].val)
    { /* 4. 不交换两树相同, 即左右子树都相同 */
        if (isomorphic(a[root1].left, b[root2].left, a, b) &&
            isomorphic(a[root1].right, b[root2].right, a, b))
            return true;
        /* 5. 交换两树相同, 即左和右相同, 右和左相同 */
        if (isomorphic(a[root1].left, b[root2].right, a, b) &&
            isomorphic(a[root1].right, b[root2].left, a, b))
            return true;
        /* 都不满足的话, 则不同构 */
        return false;
    }
    else
        return false;
}

int main()
{
    int i;
    int n, m;

    char val;
    char left, right;

    cin >> n;
    vector<tnode> a(n);
    vector<int> check1(n);

    for (i = 0; i < n; i++)
    {
        cin >> val >> left >> right;

        a[i].val = val;

        if (left != '-')
        {
            a[i].left = left - '0';
            check1[a[i].left] = 1;
        }
        else
            a[i].left = -1;

        if (right != '-')
        {
            a[i].right = right - '0';
            check1[a[i].right] = 1;
        }
        else
            a[i].right = -1;
    }

    cin >> m;

    if (n != m)
    {
        cout << "No" << endl;
        return 0;
    }

    vector<tnode> b(m);
    vector<int> check2(m);

    for (i = 0; i < m; i++)
    {
        cin >> val >> left >> right;

        b[i].val = val;

        if (left != '-')
        {
            b[i].left = left - '0';
            check2[b[i].left] = 1;
        }
        else
            b[i].left = -1;

        if (right != '-')
        {
            b[i].right = right - '0';
            check2[b[i].right] = 1;
        }
        else
            b[i].right = -1;
    }

    int root1 = -1;
    int root2 = -1;

    for (i = 0; i < n; i++)
        if (!check1[i])
        {
            root1 = i;
            break;
        }

    for (i = 0; i < m; i++)
        if (!check2[i])
        {
            root2 = i;
            break;
        }

    if (isomorphic(root1, root2, a, b))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
