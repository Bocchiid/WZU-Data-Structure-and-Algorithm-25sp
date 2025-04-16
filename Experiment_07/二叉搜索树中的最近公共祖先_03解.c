/* 该解法为迭代解法 */
/* 注意利用BST的性质 */
/* 本题的坑, 得先判断两结点是否在树中 */

int find(Tree root, int val)
{ /* 利用BST的性质 */
    while (root)
    { /* 类似于二分查找, 查找指定结点 */
        if (root->Key == val)
            return 1;
        else if (root->Key > val)
            root = root->Left;
        else if (root->Key < val) /* else */
            root = root->Right;
    }

    return 0;
}

int match(int a[], int size, int val)
{
    for (int i = 0; i < size; i++)
        if (a[i] == val)
            return 1;

    return 0;
}

int LCA( Tree T, int u, int v )
{
    if (find(T, u) && find(T, v))
    {
        int a[101];
        int size = 0;

        Tree p = T;

        while (p)
        {
            a[size] = p->Key;
            size++;
            
            if (p->Key == u)
                break;
            else if (p->Key > u)
                p = p->Left;
            else if (p->Key < u) /* else */
                p = p->Right;
        }

        p = T;
        int ans = -1;

        while (p)
        {
            if (match(a, size, p->Key))
                ans = p->Key;

            if (p->Key > v)
                p = p->Left;
            else if (p->Key < v)
                p = p->Right;
            else
                break; /* 查询到自己时, 查询结束 */
        }

        return ans;
    }

    return ERROR;
}
