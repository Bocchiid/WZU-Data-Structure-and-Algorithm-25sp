ElementType Find( List L, int m )
{
    List slow, fast;
    int i;

    slow = fast = L;

    for (i = 0; fast && i < m; i++)
        fast = fast->Next;

    if (i != m)
        return ERROR;
    
    while (fast)
    {
        fast = fast->Next;
        slow = slow->Next;
    }

    return slow->Data;
}
