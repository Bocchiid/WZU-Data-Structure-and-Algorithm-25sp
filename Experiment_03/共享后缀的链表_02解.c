PtrToNode Suffix( List L1, List L2 )
{
    int length1 = 0;
    int length2 = 0;
    List p, q;

    p = L1;

    while (p)
    {
        length1++;
        p = p->Next;
    }

    q = L2;

    while (q)
    {
        length2++;
        q = q->Next;
    }

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
            break; // 或者直接return p; | return q;
        
        p = p->Next;
        q = q->Next;
    }

    return p; // return q;
}
