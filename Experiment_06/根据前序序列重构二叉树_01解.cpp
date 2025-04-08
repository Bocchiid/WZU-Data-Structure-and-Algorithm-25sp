/* 该解法的思路从前序遍历入手 */
/* 关键在于如何知道访问结点时的时间节点 */

#include <iostream>
#include <vector>
using namespace std;

struct tnode
{
    string val;
    tnode *left;
    tnode *right;

    tnode(string val) : val(val), left(nullptr), right(nullptr) {}
    tnode(string val, tnode *left, tnode *right) : val(val), left(left), right(right) {}
};

int n;
int cnt; /* cnt用于记录访问时的当前时间节点 */

tnode* buildTree(vector<string> a)
{
    if (cnt >= n || a[cnt] == "#")
    {
        cnt++;
        return nullptr;
    }

    tnode *root = new tnode(a[cnt]);
    cnt++;

    root->left = buildTree(a);
    root->right = buildTree(a);

    return root;
}

void preorder(tnode *root)
{
    if (root)
    {
        cout << root->val << endl;
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    int i;

    cin >> n;
    vector<string> a(n);

    for (i = 0; i < n; i++)
        cin >> a[i];

    cnt = 0;
    tnode *root = buildTree(a);
    preorder(root);

    return 0;
}
