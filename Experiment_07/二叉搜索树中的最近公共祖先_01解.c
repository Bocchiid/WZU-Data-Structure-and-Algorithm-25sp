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

int LCA( Tree T, int u, int v )
{
    if (find(T, u) && find(T, v))
    {
        while (T)
        {
            if (T->Key > u && T->Key > v)
                T = T->Left;
            else if (T->Key < u && T->Key < v)
                T = T->Right;
            else
                break;
        }

        if (T)
            return T->Key;

        return -1; /* 其实这个不写没事, 题目没有考虑 */
    }

    return ERROR;
}
