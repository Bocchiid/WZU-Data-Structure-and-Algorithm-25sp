struct ListNode *createlist()
{
    struct ListNode *L = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
    L->next = NULL; // L->next = nullptr;
    struct ListNode *s;
    struct ListNode *tail = L;
    int num;

    scanf("%d", &num);

    while (num != -1)
    {
        s = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
        s->data = num;
        s->next = NULL; // s->next = nullptr;
        tail->next = s;
        tail = s;
        scanf("%d", &num);
    }

    return L->next;
}
struct ListNode *deleteeven( struct ListNode *head )
{
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
    dummy->next = head;
    struct ListNode *p, *q;

    q = dummy;
    p = dummy->next; // p = head;

    while (p)
    {
        if (p->data % 2 == 0)
            q->next = p->next;
        else
            q = p;
        
        p = p->next;
    }

    return dummy->next;
}
