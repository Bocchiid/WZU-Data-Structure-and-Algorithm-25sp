/* 该题可以转化为逆置链表 + 寻找第k个元素 */
/* 链表逆置可以用逆置链表或者头插法 */
/* 因为题目说在不改变链表的前提下, 所以求得元素后, 记得再把链表逆置一遍 */

ElementType Find( List L, int m )
{
    List p, q, next;

    int length = 0;
    q = NULL;
    p = L;

    while (p)
    {
        length++;
        next = p->Next;
        p->Next = q;
        q = p;
        p = next;
    }

    length--;
    L = q;
    
    if (m > length)
        return ERROR;
    else
    {
        p = L;
        ElementType num;

        for (int i = 1; i < m; i++)
            p = p->Next;

        num = p->Data;
        q = NULL;
        p = L;
    
        while (p)
        {
            next = p->Next;
            p->Next = q;
            q = p;
            p = next;
        }

        return num;
    }
}
