/* 该解法为带虚拟头节点的解法, 所以不需要进行特判 */

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
    List dummy = (List)malloc(sizeof(struct LNode) * 1);
    dummy->Next = L;
    Position p, q;

    q = dummy;
    p = dummy->Next; // p = L;

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

        return dummy->Next;
    }
    else
    {
        printf("Wrong Position for Insertion\n");

        return ERROR;
    }
}
List Delete( List L, Position P )
{
    List dummy = (List)malloc(sizeof(struct LNode) * 1);
    dummy->Next = L;
    Position p, q;

    q = dummy;
    p = dummy->Next; // p = L;

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
        free(p); // 这句话可以不要

        return dummy->Next;
    }
    else
    {
        printf("Wrong Position for Deletion\n");

        return ERROR;
    }
}
