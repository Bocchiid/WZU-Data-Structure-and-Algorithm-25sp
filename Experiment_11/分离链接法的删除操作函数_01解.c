bool Delete( HashTable H, ElementType Key )
{
    Index pos;
    List p, q;

    pos = Hash(Key, H->TableSize);
    q = &H->Heads[pos];
    p = q->Next;

    while (p)
    {
        if (strcmp(p->Data, Key) == 0)
        {
            q->Next = p->Next;
            printf("%s is deleted from list Heads[%d]\n", Key, pos);

            return true;
        }
        else
            q = p;

        p = p->Next;
    }

    return false;
}
