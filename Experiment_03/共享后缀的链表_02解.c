PtrToNode Suffix( List L1, List L2 )
{
    int length1 = 0;
    int length2 = 0;
    List p;

    p = L1;

    while (p)
    {
        length1++;
        p = p->Next;
    }

    p = L2;

    while (p)
    {
        length2++;
        p = p->Next;
    }

    List q;

    p = L1;
    q = L2;

    if (length1 < length2)
    {
        for (int i = 0; i < length2 - length1; i++)
            q = q->Next;
    }
    else
    {
        for (int i = 0; i < length1 - length2; i++)
            p = p->Next;
    }

    while (p && q)
    {
        if (p == q)
            break; // return p; | return q;

        p = p->Next;
        q = q->Next;
    }

    return p; // return q;
}
