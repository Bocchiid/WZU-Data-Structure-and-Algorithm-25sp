List MakeEmpty()
{
    List L = (List)malloc(sizeof(struct LNode) * 1);
    L->Next = NULL;

    return L;
}
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
bool Insert( List L, ElementType X, Position P )
{
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

        return true;
    }
    else
    {
        printf("Wrong Position for Insertion\n");

        return false;
    }
}
bool Delete( List L, Position P )
{
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
        free(p); // 这句话可以不要

        return true;
    }
    else
    {
        printf("Wrong Position for Deletion\n");

        return false;
    }
}
