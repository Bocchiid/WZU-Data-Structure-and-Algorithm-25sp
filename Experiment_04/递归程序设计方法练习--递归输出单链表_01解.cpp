/* 此解法为递归解法, 符合题目要求 */

void ListPrint_L_Rec(LinkList L)
{
    if (L)
    {
        printf(" %d", L->data);
        ListPrint_L_Rec(L->next);
    }
}
