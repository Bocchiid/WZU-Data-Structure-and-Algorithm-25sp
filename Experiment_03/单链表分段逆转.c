void K_Reverse( List L, int K )
{
    int length = 0;
    List p;

    p = L->Next;

    while (p)
    {
        length++;
        p = p->Next;
    }

    List q, next;
    List qtail, tail;

    p = L->Next;
    qtail = L;
    tail = L->Next; // qtail->Next;

    while (length >= K)
    {
        q = NULL;

        for (int i = 0; i < K; i++)
        {
            next = p->Next;
            p->Next = q;
            q = p;
            p = next;
        }

        qtail->Next = q;
        tail->Next = p;
        qtail = tail;
        tail = p;
        length -= K;
    }
}
