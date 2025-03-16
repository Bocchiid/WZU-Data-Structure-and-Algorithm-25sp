/* 该解法为带头节点链表的解法, 推荐使用带头结点链表, 不然有你好受的 */
/* typedef用一下, 不然代码太长了, 写起来有你好受的 */

struct stud_node *createlist()
{
    typedef struct stud_node node;
    node *dummy = (node*)malloc(sizeof(node) * 1);
    node *s;
    node *tail = dummy;
    int num;

    scanf("%d", &num);

    while (num != 0) // while (num)也行
    {
        s = (node*)malloc(sizeof(node) * 1);
        s->num = num;
        scanf("%s %d", s->name, &s->score);
        tail->next = s;
        tail = s;
        scanf("%d", &num);
    }

    return dummy->next;
}
struct stud_node *deletelist( struct stud_node *head, int min_score )
{
    typedef struct stud_node node;
    node *dummy = (node*)malloc(sizeof(node) * 1);
    dummy->next = head;
    node *p, *q;

    q = dummy;
    p = dummy->next; // p = head;

    while (p)
    {
        if (p->score < min_score)
            q->next = p->next;
        else
            q = p;

        p = p->next;
    }

    return dummy->next;
}
