/* 该解中所有函数均为递归实现 */
/* 删除的结点有左右子树情况时, 采用的是将左子树的最大值替换的办法 */

BinTree Insert( BinTree BST, ElementType X )
{ /* 找到空结点, 即为插入的位置 */
    if (!BST) // if (BST == NULL)
    { /* 构建二叉树结点, 且为叶子结点 */
        BinTree s = (BinTree)malloc(sizeof(struct TNode) * 1);
        s->Data = X;
        s->Left = NULL;
        s->Right = NULL;

        return s;
    }
    /* 类似于二分查找, 递归的寻找插入的位置 */
    if (BST->Data > X)
        BST->Left = Insert(BST->Left, X);
    else if (BST->Data < X) /* else */
        BST->Right = Insert(BST->Right, X);

    return BST;
}
BinTree Delete( BinTree BST, ElementType X )
{ /* 如果X不在树中, 则printf("Not Found\n"); */
    if (!BST) // if (BST == NULL)
        printf("Not Found\n");
    else
    { /* 类似于二分查找, 递归的寻找需被删除的元素 */
        if (BST->Data == X)
        { /* 1. 删除的结点为叶子结点 */
            if (!BST->Left && !BST->Right) // if (BST->Left == NULL && BST->Right == NULL)
                BST = NULL;
            else if (BST->Left && !BST->Right) // if (BST->Left != NULL && BST->Right == NULL)
                BST = BST->Left; /* 2. 删除的结点只有左子树 */
            else if (!BST->Left && BST->Right) // if (BST->Left == NULL && BST->Right != NULL)
                BST = BST->Right; /* 3. 删除的结点只有右子树 */
            else if (BST->Left && BST->Right) /* else */
            { /* 4. 删除的结点左右子树都有 */
                BinTree temp = FindMax(BST->Left);
                BST->Data = temp->Data;
                Delete(BST->Left, BST->Data);
                /* 此处选择了将左子树的最大值替换的办法 */
                /* 也可以选择将右子树的最小值替换的办法 */
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
{ /* 如果找不到, 则return NULL */
    if (!BST) // if (BST == NULL)
        return NULL;
    /* 类似于二分查找, 递归的寻找元素 */
    if (BST->Data == X)
        return BST;
    else if (BST->Data > X)
        return Find(BST->Left, X);
    else if (BST->Data < X) /* else */
        return Find(BST->Right, X);
}
Position FindMin( BinTree BST )
{ /* BST的最小值在最左下角 */
    if (!BST) // if (BST == NULL)
        return NULL;

    if (!BST->Left) // if (BST->Left == NULL)
        return BST;

    return FindMin(BST->Left);
}
Position FindMax( BinTree BST )
{ /* BST的最大值在最右下角 */
    if (!BST) // if (BST == NULL)
        return NULL;

    if (!BST->Right) // if (BST->Right == NULL)
        return BST;

    return FindMax(BST->Right);
}
