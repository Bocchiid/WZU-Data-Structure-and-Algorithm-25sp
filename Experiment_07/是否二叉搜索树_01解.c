/* 该解法的思路为利用BST的中序遍历为上升序列的特点 */
/* 该解法为中序遍历的迭代实现 */

bool IsBST ( BinTree T )
{ /* 空树也是BST */
    if (!T) // if (T == NULL)
        return true;

    BinTree stk[101];
    int top = -1;

    BinTree p = T;
    int last = -1;

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

            if (p->Data <= last)
                return false;

            last = p->Data;
            p = p->Right;
        }
    }

    return true;
}
