/* 既然是边建立链表, 边逆序, 那直接用头插法就OK了 */
/* 不要用尾插法 + 链表逆置 */
/* typedef用一下, 不然代码太长了, 写起来有你好受的 */

struct ListNode *createlist()
{
    typedef struct ListNode node;
    node *dummy = (node*)malloc(sizeof(node) * 1);
    dummy->next = NULL;
    node *s;
    int num;

    scanf("%d", &num);

    while (num != -1)
    {
        s = (node*)malloc(sizeof(node) * 1);
        s->data = num;
        s->next = dummy->next;
        dummy->next = s;
        scanf("%d", &num);
    }

    return dummy->next;
}
