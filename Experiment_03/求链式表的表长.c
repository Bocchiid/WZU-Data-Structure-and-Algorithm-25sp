int Length( List L )
{
    int length = 0;
    List p;

    p = L;

    while (p)
    {
        length++;
        p = p->Next;
    }

    return length;
}
