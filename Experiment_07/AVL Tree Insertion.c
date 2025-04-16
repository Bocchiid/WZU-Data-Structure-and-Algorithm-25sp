/* 此题的准备工作较多 */
/* 需先完成 */
/* 1. max
   2. getHeight
   3. LL
   4. RR
   5. LR
   6. RL 
   7. createTnode(可选) */

int max(int a, int b)
{
    if (a > b)
        return a;

    return b;
}

int getHeight(AVLTree root)
{
    if (root)
        return root->Height;

    return 0;
}

AVLTree LL(AVLTree root)
{
    AVLTree new_root = root->Left;
    root->Left = new_root->Right;
    new_root->Right = root;
    
    root->Height = max(getHeight(root->Left), getHeight(root->Right)) + 1;
    new_root->Height = max(getHeight(new_root->Left), getHeight(new_root->Right)) + 1;

    return new_root;
}

AVLTree RR(AVLTree root)
{
    AVLTree new_root = root->Right;
    root->Right = new_root->Left;
    new_root->Left = root;

    root->Height = max(getHeight(root->Left), getHeight(root->Right)) + 1;
    new_root->Height = max(getHeight(new_root->Left), getHeight(new_root->Right)) + 1;

    return new_root;
}

AVLTree LR(AVLTree root)
{
    root->Left = RR(root->Left);

    return LL(root);
}

AVLTree RL(AVLTree root)
{
    root->Right = LL(root->Right);

    return RR(root);
}

AVLTree createTnode(int val)
{
    AVLTree root = (AVLTree)malloc(sizeof(struct AVLNode) * 1);
    root->Data = val;
    root->Left = NULL;
    root->Right = NULL;
    root->Height = 0;

    return root;
}

AVLTree Insert ( int Key, AVLTree T )
{
    if (!T) // if (T == NULL)
        T = createTnode(Key);
    else
    { /* 类似于二分查找, 递归的查找插入位置 */
        if (T->Data > Key)
        {
            T->Left = Insert(Key, T->Left);

            if (getHeight(T->Left) - getHeight(T->Right) == 2)
            {
                if (T->Left->Data > Key)
                    T = LL(T);
                else
                    T = LR(T);
            }
        }
        else if (T->Data < Key)
        {
            T->Right = Insert(Key, T->Right);
            
            if (getHeight(T->Right) - getHeight(T->Left) == 2)
            {
                if (T->Right->Data < Key)
                    T = RR(T);
                else
                    T = RL(T);
            }
        }
    }

    T->Height = max(getHeight(T->Left), getHeight(T->Right)) + 1;

    return T;
}
