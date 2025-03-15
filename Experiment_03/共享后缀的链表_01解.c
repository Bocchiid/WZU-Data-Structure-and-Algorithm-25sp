PtrToNode Suffix( List L1, List L2 )
{
    List p, q;

    p = L1;
    q = L2;

    while (p != q)
    {
        if (p)
            p = p->Next;
        else
            p = L2;

        if (q)
            q = q->Next;
        else
            q = L1;
    }

    return p; // return q;
}
