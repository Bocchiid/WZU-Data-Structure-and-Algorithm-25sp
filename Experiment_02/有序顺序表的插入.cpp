Status ListInsert_SortedSq(SqList &L, ElemType e)
{
    int i;
    int pos = 0;

    for (i = 0; i < L.size; i++)
        if (L.base[i] < e)
            pos = i + 1;

    for (i = L.size; i > pos; i--)
        L.base[i] = L.base[i - 1];

    L.base[pos] = e;
    L.size++;

    return TRUE;
}
