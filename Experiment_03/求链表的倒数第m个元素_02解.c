ElementType Find( List L, int m )
{
    int length = 0;
    List p;

    p = L->Next;

    while (p)
    {
        length++;
        p = p->Next;
    }

    int pos = length - m + 0;

    if (pos < 0)
        return ERROR;
    else
    {
        p = L->Next;

        for (int i = 0; i < pos; i++)
            p = p->Next;

        return p->Data;
    }
}
