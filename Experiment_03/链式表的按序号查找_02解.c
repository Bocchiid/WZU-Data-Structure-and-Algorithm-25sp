ElementType FindKth( List L, int K )
{
    if (K < 1)
        return ERROR;
    /* 上面这段特判可以不要, 因为若K < 1, while只会在p == NULL时退出 */
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
