/* 该解法的思路为从递归的定义出发 */

bool dfs(BinTree T, int lower, int upper)
{ /* 空树也是BST */
    if (!T) // if (T == NULL)
        return true;
    /* 若不满足左大于根小于右的话, return false; */
    if (lower >= T->Data || upper <= T->Data)
        return false;
    /* 递归左右子树是否满足BST */
    return dfs(T->Left, lower, T->Data) &&
           dfs(T->Right, T->Data, upper);
}

bool IsBST ( BinTree T )
{ /* 初始的lower和upper是猜的, 一般只要lower够小, upper够大, 就能过OJ */
    return dfs(T, -1, 1001);
}
