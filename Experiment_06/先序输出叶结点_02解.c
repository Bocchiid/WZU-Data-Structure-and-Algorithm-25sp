/* 这道题的解法就是前序遍历 + 叶结点的判断 */
/* 该解法为迭代解法 */

void PreorderPrintLeaves( BinTree BT )
{
    if (!BT) // if (BT == NULL)
        return;

    BinTree stk[101];
    int top = -1;

    top++;
    stk[top] = BT;

    while (top != -1)
    {
        BinTree t = stk[top];
        top--;

        if (!t->Left && !t->Right)
            printf(" %c", t->Data);

        if (t->Right)
        {
            top++;
            stk[top] = t->Right;
        }

        if (t->Left)
        {
            top++;
            stk[top] = t->Left;
        }
    }
}
