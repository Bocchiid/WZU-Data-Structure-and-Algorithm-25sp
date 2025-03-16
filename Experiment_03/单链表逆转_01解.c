List Reverse( List L )
{
    List p, q, next;

    q = NULL;
    p = L;

    while (p)
    {
        next = p->Next;
        p->Next = q;
        q = p;
        p = next;
    }

    L = q;

    return L; // 直接返回q也行(return q;)
}
