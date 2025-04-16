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
/* 该解法的the K-th largest key为(2)的递归实现 */
/* 访问为维护全局变量次数K, 和K-th的值 */

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

int C;
int ans;

void inorder(BinTree root)
{
    if (root)
    {
        inorder(root->Right);

        if (C == 1)
        {
            ans = root->Key;
            C--; /* 破坏掉全局的条件, 防止ans被更新 */

            return; /* 最优性剪枝 */
        }
        else
            C--;
        
        inorder(root->Left);
    }
}

int CheckBST ( BinTree T, int K )
{
    if (isBST(T))
    {
        ans = -1; /* 其实这个不写也没事, 本题没有考虑 */
        C = K;
        inorder(T);

        return ans;
    }
    else
        return -getHeight(T);
}
