bool Delete( HashTable H, ElementType Key )
{
    Index pos;
    List p, q;

    pos = Hash(Key, H->TableSize);
    struct LNode s = H->Heads[pos];
    p = s.Next;

    while (p)
    {
        if (strcmp(p->Data, Key) == 0)
        {
            if (p == s.Next)
                H->Heads[pos].Next = p->Next;
            else
            {
                q = s.Next;

                while (q->Next != p)
                    q = q->Next;

                q->Next = p->Next;
            }

            printf("%s is deleted from list Heads[%d]\n", Key, pos);

            return true;
        }

        p = p->Next;
    }

    return false;
}
