void InorderTraversal( BinTree BT )
{
    if (BT)
    {
        InorderTraversal(BT->Left);
        printf(" %c", BT->Data);
        InorderTraversal(BT->Right);
    }
}
void PreorderTraversal( BinTree BT )
{
    if (BT)
    {
        printf(" %c", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}
void PostorderTraversal( BinTree BT )
{
    if (BT)
    {
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf(" %c", BT->Data);
    }
}
void LevelorderTraversal( BinTree BT )
{
    if (!BT) // if (BT == NULL)
        return;

    BinTree q[1001];
    int head = 0;
    int tail = 0;

    q[tail] = BT;
    tail++;

    while (head != tail)
    {
        BinTree t = q[head];

        if (t->Left)
        {
            q[tail] = t->Left;
            tail++;
        }

        if (t->Right)
        {
            q[tail] = t->Right;
            tail++;
        }

        printf(" %c", t->Data);
        head++;
    }
}
