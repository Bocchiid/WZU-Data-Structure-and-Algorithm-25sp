/* 该解中Find, FindMin, FindMax均为迭代实现 */
/* 删除的结点有左右子树情况时, 采用的是将右子树的最小值替换的办法 */

BinTree createTnode(ElementType val)
{
    BinTree root = (BinTree)malloc(sizeof(struct TNode) * 1);
    root->Data = val;
    root->Left = NULL;
    root->Right = NULL;

    return root;
}

BinTree Insert( BinTree BST, ElementType X )
{ /* 空结点即为可插入的结点/位置 */
    if (!BST) // if (BST == NULL)
    { /* 构建要插入的结点 */
        BinTree s = createTnode(X);

        return s;
    }
    /* 类似于二分查找, 寻找插入位置 */
    if (BST->Data > X)
        BST->Left = Insert(BST->Left, X);
    else if (BST->Data < X) /* else */
        BST->Right = Insert(BST->Right, X);
    /* 返回插入完成后的根结点 */
    return BST;
}
BinTree Delete( BinTree BST, ElementType X )
{
    if (!BST) // if (BST == NULL)
        printf("Not Found\n");
    else
    { /* 类似于二分查找, 寻找需被删除的结点 */
        if (BST->Data == X)
        { /* 1. 删除叶子结点 */
            if (!BST->Left && !BST->Right) // if (BST->Left == NULL && BST->Right == NULL)
                BST = NULL;
            else if (BST->Left && !BST->Right) // if (BST->Left != NULL && BST->Right == NULL)
                BST = BST->Left; /* 2. 删除的结点只有左子树 */
            else if (!BST->Left && BST->Right) // if (BST->Left == NULL && BST->Right != NULL)
                BST = BST->Right; /* 3. 删除的结点只有右子树 */
            else if (BST->Left && BST->Right) // if (BST->Left != NULL && BST->Right != NULL) /* else */
            { /* 4. 删除的结点有左右子树 */
                BinTree t = FindMin(BST->Right);
                BST->Data = t->Data;
                Delete(BST->Right, BST->Data);
                /* 此处选择了将右子树的最小值替换的办法 */
                /* 也可以选择将左子树的最大值替换的办法 */
            }
        }
        else if (BST->Data > X)
            BST->Left = Delete(BST->Left, X);
        else if (BST->Data < X) /* else */
            BST->Right = Delete(BST->Right, X);
    }
    /* return 删除结点后的根结点BST */
    return BST;
}
Position Find( BinTree BST, ElementType X )
{ /* Find的迭代实现 */
    while (BST)
    { /* 类似于二分查找, 寻找需被查询的结点 */
        if (BST->Data == X)
            return BST;
        else if (BST->Data > X)
            BST = BST->Left;
        else if (BST->Data < X) /* else */
            BST = BST->Right;
    }
    /* 若在BST中找不到X, 则退出循环, 此时BST = NULL */
    return BST; // return NULL;
}
Position FindMin( BinTree BST )
{ /* FindMin的迭代实现 */
    if (BST) // if (BST != NULL)
        while (BST->Left) // while (BST->Left != NULL)
            BST = BST->Left;
    /* 若BST为空树, 则退出if, 此时BST = NULL */
    return BST;
}
Position FindMax( BinTree BST )
{ /* FindMax的迭代实现 */
    if (BST) // if (BST != NULL)
        while (BST->Right) // while (BST->Right != NULL)
            BST = BST->Right;
    /* 若BST为空树, 则退出if, 此时BST = NULL */
    return BST;
}
