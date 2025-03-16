/* 该解法为利用头插法逆置链表的解法 */

List Reverse( List L )
{
    List dummy = (List)malloc(sizeof(struct Node) * 1);
    dummy->Next = NULL;
    List p;
    List s;

    p = L;

    while (p)
    {
        s = (List)malloc(sizeof(struct Node) * 1);
        s->Data = p->Data;
        s->Next = dummy->Next;
        dummy->Next = s;
        p = p->Next;
    }

    if (L)
        L->Next = NULL; // 由输出样例可以知道, L1逆置后应该只有一个结点, 前提是L1不为空

    return dummy->Next;
}
