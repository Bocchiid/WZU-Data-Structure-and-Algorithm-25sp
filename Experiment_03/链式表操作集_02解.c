/* 该解法为不带头结点的解法, 所以尤其是对头节点的操作需进行对应情况的特判 */

Position Find( List L, ElementType X )
{
    Position p;

    p = L;

    while (p)
    {
        if (p->Data == X)
            return p;

        p = p->Next;
    }

    return ERROR;
}
List Insert( List L, ElementType X, Position P )
{
    if (L == P) /* 插入在头节点之前 */
    {
        Position s = (Position)malloc(sizeof(struct LNode) * 1);
        s->Data = X;
        s->Next = L; // s->Next = P;
        L = s;

        return L; // 当然也可以直接return s;
    }

    Position p, q;

    q = L;
    p = L->Next; // p = q->Next;

    while (p)
    {
        if (p == P)
            break;

        q = p;
        p = p->Next;
    }

    if (p == P)
    {
        Position s = (Position)malloc(sizeof(struct LNode) * 1);
        s->Data = X;
        s->Next = q->Next;
        q->Next = s;

        return L;
    }
    else
    {
        printf("Wrong Position for Insertion\n");

        return ERROR;
    }
}
List Delete( List L, Position P )
{    /* 题目不严谨, 没有考虑空表的情况 */
    if (L == P) /* 删除头结点 */
    {
        L = L->Next;

        return L;
    }

    Position p, q;

    q = L;
    p = L->Next; // p = q->Next;

    while (p)
    {
        if (p == P)
            break;

        q = p;
        p = p->Next;
    }

    if (p == P) // if (p)也行
    {
        q->Next = p->Next;
        free(p); // 这句话不要也行

        return L;
    }
    else
    {
        printf("Wrong Position for Deletion\n");

        return ERROR;
    }
}
