/* typedef用不用都行, 看个人习惯 */

struct ListNode *reverse( struct ListNode *head )
{
    typedef struct ListNode node;
    node *p, *q, *next;

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

    return head; // 或者直接返回q也行(return q;)
}
