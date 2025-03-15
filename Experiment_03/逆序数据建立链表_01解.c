struct ListNode *createlist()
{
    struct ListNode *L = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
    L->next = NULL; // L->next = nullptr;
    struct ListNode *s;
    int num;

    scanf("%d", &num);

    while (num != -1)
    {
        s = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
        s->data = num;
        s->next = L->next;
        L->next = s;
        scanf("%d", &num);
    }

    return L->next;
}
