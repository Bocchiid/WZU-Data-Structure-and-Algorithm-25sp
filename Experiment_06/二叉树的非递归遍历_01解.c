/* 该解法为二叉树的非递归遍历的一种实现方式 */

void InorderTraversal( BinTree BT )
{
    if (!BT) // if (BT == NULL)
        return;

    Stack stk = CreateStack();
    BinTree p = BT;

    while (p || !IsEmpty(stk))
    {
        if (p)
        {
            Push(stk, p);
            p = p->Left;
        }
        else
        {
            p = Pop(stk);
            printf(" %c", p->Data);
            p = p->Right;
        }
    }
}
void PreorderTraversal( BinTree BT )
{
    if (!BT) // if (BT == NULL)
        return;

    Stack stk = CreateStack();
    Push(stk, BT);

    while (!IsEmpty(stk))
    {
        BinTree t = Pop(stk);

        if (t->Right)
            Push(stk, t->Right);

        if (t->Left)
            Push(stk, t->Left);

        printf(" %c", t->Data);
    }
}
void PostorderTraversal( BinTree BT )
{
    if (!BT) // if (BT == NULL)
        return;

    Stack stk = CreateStack();
    Push(stk, BT);
    Stack ans = CreateStack();

    while (!IsEmpty(stk))
    {
        BinTree t = Pop(stk);

        if (t->Left)
            Push(stk, t->Left);

        if (t->Right)
            Push(stk, t->Right);

        Push(ans, t);
    }

    while (!IsEmpty(ans))
    {
        BinTree t = Pop(ans);
        printf(" %c", t->Data);
    }
}
