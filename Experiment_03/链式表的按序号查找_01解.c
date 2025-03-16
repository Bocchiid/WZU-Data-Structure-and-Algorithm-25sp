ElementType FindKth( List L, int K )
{
    if (K < 1)
        return ERROR;

    List p;

    p = L;

    for (int i = 1; i < K; i++)
        if (p)
            p = p->Next;
        else
            return ERROR;

    if (p)
        return p->Data;
    else
        return ERROR;
}
