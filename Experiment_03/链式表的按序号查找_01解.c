ElementType FindKth( List L, int K )
{
    if (K < 1)
        return ERROR;

    int cnt = 1;
    List p;

    p = L;

    while (p)
    {
        if (cnt == K)
            return p->Data;

        cnt++;
        p = p->Next;
    }

    return ERROR;
}
