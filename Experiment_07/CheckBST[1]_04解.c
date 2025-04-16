/* 本题的题意拆解完后得到的要求为 */
/* 1. isBST */
/* 2. getHeight */
/* 3. the K-th largest key */
/* 其中, 3的实现为本题的核心 */
/* 可以利用BST的中序遍历为递增序列的特点 */
/* (1). 第K大的值即为序列的倒数第K个值 */
/* (2). 改造中序遍历为右中左, 当第K次访问时, 即为要找的值 */

/* 声明: */
/* 本题所有题解的isBST均为中序遍历的迭代实现 */
/* 本题所有题解的getHeight均为定义出发的实现 */
/* 该解法的the K-th largest key为(1)的递归实现 */
/* 访问内容为维护中序遍历得到的递增序列(全局) */

int isBST(BinTree root)
{
    if (!root) // if (root == NULL)
        return 1;

    BinTree stk[101];
    int top = -1;

    BinTree p = root;
    int last = -1;

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

            if (p->Key <= last)
                return 0;

            last = p->Key;
            p = p->Right;
        }
    }

    return 1;
}

int getHeight(BinTree root)
{
    if (!root) // if (root == NULL)
        return 0;

    int leftHeight = getHeight(root->Left);
    int rightHeight = getHeight(root->Right);
    int maxHeight = leftHeight;

    if (rightHeight > maxHeight)
        maxHeight = rightHeight;

    return maxHeight + 1;
}

int a[101];
int size;

void inorder(BinTree root)
{
    if (root)
    {
        inorder(root->Left);

        a[size] = root->Key;
        size++;

        inorder(root->Right);
    }
}

int CheckBST ( BinTree T, int K )
{
    if (isBST(T))
    {
        size = 0;
        inorder(T);

        return a[size - K];
    }
    else
        return -getHeight(T);
}
