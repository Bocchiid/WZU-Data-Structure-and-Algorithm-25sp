/* 可以利用BST的中序遍历为递增序列的特点 */
/* (1). 第K小的值即为序列的正数第K个值 */
/* (2). 中序遍历, 当第K次访问时, 即为要找的值 */

/* 该解法为(1)的递归实现 */
/* 访问内容为维护全局次数K和ans */

int C;
BinTree ans;

void inorder(BinTree root)
{
    if (root)
    {
        inorder(root->Left);

        if (C == 1)
        {
            ans = root;
            C--; /* 破坏掉全局的条件, 防止ans被更新 */

            return; /* 最优性剪枝 */
        }
        else
            C--;

        inorder(root->Right);
    }
}

BinTree KthSmallest ( BinTree T, int K )
{
    ans = NULL; /* 其实这个不写也没事, 本题没有考虑 */
    C = K;
    inorder(T);

    return ans;
}
