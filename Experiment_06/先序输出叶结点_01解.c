/* 这道题的解法就是前序遍历 + 叶结点的判断 */
/* 该解法为递归解法 */

void PreorderPrintLeaves( BinTree BT )
{
    if (BT)
    {
        if (!BT->Left && !BT->Right)
            printf(" %c", BT->Data);
        
        PreorderPrintLeaves(BT->Left);
        PreorderPrintLeaves(BT->Right);
    }
}
