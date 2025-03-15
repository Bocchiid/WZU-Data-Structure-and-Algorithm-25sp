List Insert( List L, ElementType X )
{
    List p, q;

    q = L;
    p = L->Next;

    while (p)
    {
        if (p->Data >= X)
            break;

        q = p;
        p = p->Next;
    }

    List s = (List)malloc(sizeof(struct Node) * 1);
    s->Data = X;
    s->Next = q->Next;
    q->Next = s;

    return L;
}
