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
            break;

        cnt++;
        p = p->Next;
    }

    if (p == NULL) // 判断p是否指向有效结点
        return ERROR;
    // 若p指向有效结点, 则p一定指向第k个结点
    return p->Data;
}
