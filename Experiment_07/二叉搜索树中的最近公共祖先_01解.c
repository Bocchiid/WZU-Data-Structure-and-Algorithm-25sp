/* 该解法为迭代解法 */
/* 注意利用BST的性质 */

int LCA( Tree T, int u, int v )
{ /* 这道题的一个坑, 得先判断两个结点是否在树中能被找到 */
    if (!T) // if (T == NULL)
        return ERROR;
    
    int found1 = 0;
    int found2 = 0;
    /* 此处使用的是中序遍历的迭代实现 */
    Tree stk[101];
    int top = -1;
    
    Tree p = T;

    while (p || top != -1)
    {
        if (p)
        {
            top++;
            stk[top] = p;
            p = p->Left;
        }
        else
        {
            p = stk[top];
            top--;

            if (p->Key == u)
                found1 = 1;

            if (p->Key == v)
                found2 = 1;
            
            p = p->Right;
        }
    }

    if (found1 && found2)
    { /* 两结点都在树中, 才有最近公共祖先 */
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
        else
            return ERROR;
    }

    return ERROR;
}
