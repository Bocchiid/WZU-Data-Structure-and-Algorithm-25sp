/* 该解为临时解, 还未经打磨 */
/* 如有不满, 还请谅解 */

BinTree Insert( BinTree BST, ElementType X )
{ /* 若遍历到空结点处, 说明找到了插入的位置 */
    if (!BST) // if (BST == NULL)
    {
        BinTree s = (BinTree)malloc(sizeof(struct TNode) * 1);
        s->Data = X;
        s->Left = NULL;
        s->Right = NULL;

        return s;
    }

    if (BST->Data > X)
        BST->Left = Insert(BST->Left, X);
    else if (BST->Data < X)
        BST->Right = Insert(BST->Right, X);

    return BST;
}
BinTree Delete( BinTree BST, ElementType X )
{
    if (!BST) // if (BST == NULL)
        printf("Not Found\n");
    else
    {
        if (BST->Data == X)
        {
            if (!BST->Left && !BST->Right)
                BST = NULL;
            else if (BST->Left && !BST->Right)
                BST = BST->Left;
            else if (!BST->Left && BST->Right)
                BST = BST->Right;
            else if (BST->Left && BST->Right) /* else */
            {
                Position temp = FindMin(BST->Right);
                BST->Data = temp->Data;
                Delete(BST->Right, BST->Data);
            }
        }
        else if (BST->Data > X)
            BST->Left = Delete(BST->Left, X);
        else if (BST->Data < X) /* else */
            BST->Right = Delete(BST->Right, X);
    }

    return BST;
}
Position Find( BinTree BST, ElementType X )
{
    if (!BST) // if (BST == NULL)
        return NULL;

    if (BST->Data == X)
        return BST;
    else if (BST->Data > X)
        return Find(BST->Left, X);
    else if (BST->Data < X) /* else */
        return Find(BST->Right, X);
}
Position FindMin( BinTree BST )
{
    if (!BST) // if (BST == NULL)
        return NULL;

    if (!BST->Left) // if (BST->Left == NULL)
        return BST;

    return FindMin(BST->Left);
}
Position FindMax( BinTree BST )
{
    if (!BST) // if (BST == NULL)
        return NULL;

    if (!BST->Right) // if (BST->Right == NULL)
        return BST;

    return FindMax(BST->Right);
}
