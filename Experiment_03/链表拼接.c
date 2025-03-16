/* 该解法为带头节点链表的解法, 推荐使用带头节点链表, 不然有你好受的 */
/* typedef用一下, 不然代码太长了, 写起来有你好受的 */

struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2)
{
    typedef struct ListNode node;
    node *dummy = (node*)malloc(sizeof(node) * 1);
    node *s;
    node *tail = dummy;

    while (list1 && list2)
    {
        s = (node*)malloc(sizeof(node) * 1);

        if (list1->data < list2->data)
        {
            s->data = list1->data;
            tail->next = s;
            tail = s;
            list1 = list1->next;
        }
        else
        {
            s->data = list2->data;
            tail->next = s;
            tail = s;
            list2 = list2->next;
        }
    }

    while (list1)
    {
        s = (node*)malloc(sizeof(node) * 1);
        s->data = list1->data;
        tail->next = s;
        tail = s;
        list1 = list1->next;
    }

    while (list2)
    {
        s = (node*)malloc(sizeof(node) * 1);
        s->data = list2->data;
        tail->next = s;
        tail = s;
        list2 = list2->next;
    }

    return dummy->next;
}
