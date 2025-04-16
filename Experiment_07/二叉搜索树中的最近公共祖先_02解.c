/* 该解法为递归解法 */
/* 注意利用BST的性质 */
/* 本题的坑, 得先判断两结点是否在树中 */

int find(Tree root, int val)
{ /* 利用BST的性质 */
    if (!root) // if (root == NULL)
        return 0;
    /* 类似于二分查找, 查找指定结点 */
    if (root->Key == val)
        return 1;

    if (root->Key > val)
        return find(root->Left, val);
    else if (root->Key < val) /* else */
        return find(root->Right, val);
}

int Lca(Tree root, int u, int v)
{
    if (root->Key > u && root->Key > v)
        return Lca(root->Left, u, v);
    else if (root->Key < u && root->Key < v)
        return Lca(root->Right, u, v);
    else
        return root->Key;
}

int LCA( Tree T, int u, int v )
{
    if (find(T, u) && find(T, v))
    {
        return Lca(T, u, v);
    }

    return ERROR;
}
