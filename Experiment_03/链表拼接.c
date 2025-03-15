struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
    dummy->next = NULL; // dummy->next = nullptr;
    struct ListNode *s;
    struct ListNode *tail = dummy;

    while (list1 && list2)
    {
        s = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);

        if (list1->data < list2->data)
        {
            s->data = list1->data;
            list1 = list1->next;
        }
        else
        {
            s->data = list2->data;
            list2 = list2->next;
        }

        tail->next = s;
        tail = s;
    }

    while (list1)
    {
        s = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
        s->data = list1->data;
        tail->next = s;
        tail = s;
        list1 = list1->next;
    }

    while (list2)
    {
        s = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
        s->data = list2->data;
        tail->next = s;
        tail = s;
        list2 = list2->next;
    }

    return dummy->next;
}
