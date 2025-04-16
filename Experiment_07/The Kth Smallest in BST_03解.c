/* 可以利用BST的中序遍历为递增序列的特点 */
/* (1). 第K小的值即为序列的正数第K个值 */
/* (2). 中序遍历, 当第K次访问时, 即为要找的值 */

/* 该解法为(1)的迭代实现 */

BinTree KthSmallest ( BinTree T, int K )
{
    if (!T) // if (T == NULL)
        return NULL; /* 其实这个不写也没事, 本题没有考虑 */

    BinTree stk[101];
    int top = -1;

    BinTree p = T;

    BinTree a[101] = {0};
    int size = 0;

    while (p || top != -1)
    {
        if (p)
        {
            top++;
            stk[top] = p;
            p = p->Left;
        }
        else
        {
            p = stk[top];
            top--;

            a[size] = p;
            size++;

            p = p->Right;
        }
    }

    return a[K - 1];
}
