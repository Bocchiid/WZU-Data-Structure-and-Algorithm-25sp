struct ListNode *reverse( struct ListNode *head )
{
    struct ListNode *p, *q, *next;

    q = NULL;
    p = head;

    while (p)
    {
        next = p->next;
        p->next = q;
        q = p;
        p = next;
    }

    head = q;

    return head;
}
