/* 注意题目描述, 该链表为带头节点链表 */
/* 本题实现的其实是链表的插入排序, 即遍历寻找插入位置 + 结点的插入两个操作 */

List Insert( List L, ElementType X )
{
    List s;
    List p, q;

    q = L;
    p = L->Next; // p = q->Next;

    while (p)
    {
        if (p->Data >= X)
            break;

        q = p;
        p = p->Next;
    }

    s = (List)malloc(sizeof(struct Node) * 1);
    s->Data = X;
    s->Next = q->Next;
    q->Next = s;

    return L;
}
