List Reverse( List L )
{
    List p, q, next;

    q = NULL; // q = nullptr;
    p = L;

    while (p)
    {
        next = p->Next;
        p->Next = q;
        q = p;
        p = next;
    }

    L = q;

    return L;
}
