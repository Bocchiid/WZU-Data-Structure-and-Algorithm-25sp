ElementType Find( List L, int m )
{
    if (L->Next == NULL) /* 空链表的情况, 但题目没有考虑 */
        return ERROR;

    int i;
    List slow, fast;

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
