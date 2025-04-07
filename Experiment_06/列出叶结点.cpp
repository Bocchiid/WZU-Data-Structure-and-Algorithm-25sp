#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct tnode
{
    int val;
    int left;
    int right;
};

int main()
{
    int i;
    int n;

    cin >> n;
    vector<tnode> a(n);   /* 用于存放树的结点 */
    vector<int> check(n); /* 用于找根 */
    /* 建立二叉树 */
    for (i = 0; i < n; i++)
    {
        char left, right;

        cin >> left >> right;

        a[i].val = i;

        if (left != '-')
        {
            a[i].left = left - '0';
            check[a[i].left] = 1;
        }
        else
            a[i].left = -1;

        if (right != '-')
        {
            a[i].right = right - '0';
            check[a[i].right] = 1;
        }
        else
            a[i].right = -1;
    }
    /* 寻找二叉树的根的位置 */
    int root;

    for (i = 0; i < n; i++)
        if (!check[i])
        {
            root = i;
            break;
        }
    /* 层序遍历bfs */
    queue<tnode> q;
    q.push(a[root]);
    bool flag = true; /* 用于格式控制 */

    while (!q.empty())
    {
        int n = q.size();

        for (i = 0; i < n; i++)
        {
            tnode t = q.front();
            q.pop();

            if (t.left == -1 && t.right == -1)
            {
                if (flag)
                {
                    cout << t.val;
                    flag = false;
                }
                else
                    cout << " " << t.val;
            }

            if (t.left != -1)
                q.push(a[t.left]);

            if (t.right != -1)
                q.push(a[t.right]);
        }
    }

    cout << endl;

    return 0;
}
