/* 本题的重点在于利用前序和中序不断的寻找根节点 */

#include <iostream>
using namespace std;

char pre[101];
char in[101];

struct tnode
{
    char val;
    tnode *left;
    tnode *right;

    tnode(char val) : val(val), left(nullptr), right(nullptr) {}
    tnode(char val, tnode *left, tnode *right) : val(val), left(left), right(right) {}
};

int getHeight(tnode *root)
{
    if (!root) // if (root == nullptr)
        return 0;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}
/* 该函数的参数为左闭右闭 */
tnode *buildTree(int b1, int e1, int b2, int e2)
{ /* 构建根结点 */
    tnode *root = new tnode(pre[b1]);

    int p = b2;
    /* 让p寻找根结点在中序遍历中的位置 */
    while (p != e2 && in[p] != pre[b1])
        p++;

    int cnt = p - b2; /* 左子树的结点的个数 */

    if (p != b2) /* 若还有左子树, 则构建左子树 */
        root->left = buildTree(b1 + 1, b1 + cnt, b2, p - 1);
     // root->left = buildTree(b1 + 1, b1 + 1 + cnt - 1, b2, p - 1);
    if (p != e2) /* 若还有右子树, 则构建右子树 */
        root->right = buildTree(b1 + cnt + 1, e1, p + 1, e2);

    return root;
}

int main()
{
    int i;
    int n;

    cin >> n;

    for (i = 0; i < n; i++)
        cin >> pre[i];

    for (i = 0; i < n; i++)
        cin >> in[i];

    tnode *root = buildTree(0, n - 1, 0, n - 1);
    cout << getHeight(root) << endl;

    return 0;
}
