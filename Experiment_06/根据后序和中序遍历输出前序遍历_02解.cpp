/* 本题的重点在于利用前序和中序不断的寻找根节点 */

#include <iostream>
using namespace std;

int post[101];
int in[101];

struct tnode
{
    int val;
    tnode *left;
    tnode *right;

    tnode(int val) : val(val), left(nullptr), right(nullptr) {}
    tnode(int val, tnode *left, tnode *right) : val(val), left(left), right(right) {}
};
/* 该函数的参数为左闭右闭 */
tnode* buildTree(int b1, int e1, int b2, int e2)
{ /* 构造根结点 */
    tnode *root = new tnode(post[e2]);

    int p = b1;
    /* 让p去寻找根结点在中序遍历中的位置 */
    while (p != e1 && in[p] != post[e2])
        p++;

    int cnt = p - b1; /* 计算左子树的结点个数 */

    if (p != b1) /* 若还有左子树, 则构建左子树 */
        root->left = buildTree(b1, p - 1, b2, b2 + cnt - 1);

    if (p != e1) /* 若还有右子树, 则构建右子树 */
        root->right = buildTree(p + 1, e1, b2 + cnt, e2 - 1);

    return root;
}   

void preorder(tnode *root)
{
    if (root)
    {
        cout << " " << root->val;
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    int i;
    int n;

    cin >> n;

    for (i = 0; i < n; i++)
        cin >> post[i];

    for (i = 0; i < n; i++)
        cin >> in[i];

    tnode *root = buildTree(0, n - 1, 0, n - 1);
    cout << "Preorder:";
    preorder(root);
    cout << endl;

    return 0;
}
