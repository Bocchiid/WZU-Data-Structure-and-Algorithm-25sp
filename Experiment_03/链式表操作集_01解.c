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
{    // dummy(虚拟头节点)的做法
    List dummy = (List)malloc(sizeof(struct LNode) * 1);
    dummy->Next = L;
    Position p, q;
    Position s;

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
        s = (Position)malloc(sizeof(struct LNode) * 1);
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
{    // dummy(虚拟头节点)的做法
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

    if (p) // p == P
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
