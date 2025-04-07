/* 树是一种递归定义的结构 */
/* 解决递归问题的两大主要思路是: 
   1. 寻找递推关系
   2. 分治思想, 寻找和解决最小子问题
*/

int GetHeight( BinTree BT )
{
    if (!BT) // if (BT == NULL)
        return 0;

    int leftHeight = GetHeight(BT->Left);
    int rightHeight = GetHeight(BT->Right);
    int maxHeight = leftHeight;

    if (rightHeight > maxHeight) // if (rightHeight > leftHeight)
        maxHeight = rightHeight;

    return maxHeight + 1;
}
