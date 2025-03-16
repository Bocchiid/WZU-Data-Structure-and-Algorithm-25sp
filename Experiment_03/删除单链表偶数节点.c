/* 题目说是节点, 但我觉得是结点, Emmm... */
/* 该解法为带头节点链表的解法, 推荐使用带头节点链表, 不然有你好受的 */
/* typedef用一下, 不然代码太长了, 写起来有你好受的 */

struct ListNode *createlist()
{
    typedef struct ListNode node;
    node *dummy = (node*)malloc(sizeof(node) * 1);
    node *s;
    node *tail = dummy;
    int num;

    scanf("%d", &num);

    while (num != -1)
    {
        s = (node*)malloc(sizeof(node) * 1);
        s->data = num;
        tail->next = s;
        tail = s;
        scanf("%d", &num);
    }

    return dummy->next;
}
struct ListNode *deleteeven( struct ListNode *head )
{
    typedef struct ListNode node;
    node *dummy = (node*)malloc(sizeof(node) * 1);
    dummy->next = head;
    node *p, *q;

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
