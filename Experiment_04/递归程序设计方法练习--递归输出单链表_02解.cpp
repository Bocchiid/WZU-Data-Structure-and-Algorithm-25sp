/* 此解法为迭代解法, 与题目要求不符 */

void ListPrint_L_Rec(LinkList L)
{
    LinkList p;

    p = L;

    while (p)
    {
        printf(" %d", p->data);

        p = p->next;
    }
}
