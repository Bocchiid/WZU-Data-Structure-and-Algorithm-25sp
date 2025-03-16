/* 该解法为利用头插法实现链表逆置 */
/* typedef用不用都行, 看个人习惯 */

struct ListNode *reverse( struct ListNode *head )
{
    typedef struct ListNode node;
    node *dummy = (node*)malloc(sizeof(node) * 1);
    dummy->next = NULL;
    node *s;
    node *p;

    p = head;

    while (p)
    {
        s = (node*)malloc(sizeof(node) * 1);
        s->data = p->data;
        s->next = dummy->next;
        dummy->next = s;
        p = p->next;
    }

    return dummy->next;
}
