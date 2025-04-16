/* 可以利用BST的中序遍历为递增序列的特点 */
/* (1). 第K小的值即为序列的正数第K个值 */
/* (2). 中序遍历, 当第K次访问时, 即为要找的值 */

/* 该解法为(1)的递归实现 */
/* 访问内容为维护中序遍历得到的递增序列(size为全局) */

int size;

void inorder(BinTree root, BinTree a[])
{
    if (root)
    {
        inorder(root->Left, a);

        a[size] = root;
        size++;

        inorder(root->Right, a);
    }
}

BinTree KthSmallest ( BinTree T, int K )
{
    BinTree a[101];
    size = 0;
    inorder(T, a);

    return a[K - 1];
}
