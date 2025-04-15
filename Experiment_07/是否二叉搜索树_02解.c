/* 该解法的思路为从递归的定义出发 */

bool dfs(BinTree T, int lower, int upper)
{ /* 空树也是BST */
    if (!T) // if (T == NULL)
        return true;
    /* 若不满足左小于根小于右的话, return false; */
    if (lower >= T->Data || upper <= T->Data)
        return false;
    /* 递归判断左右子树是否满足BST */
    return dfs(T->Left, lower, T->Data) &&
           dfs(T->Right, T->Data, upper);
}

bool IsBST ( BinTree T )
{ /* 初始的lower和upper是猜的, 一般只要lower够小, upper够大, 就能过OJ */
    return dfs(T, -1, 1001);
  /* 经过大量的数据测试, dfs(T, 30, 234); 刚好能过所有测试点 */
  /* 即本题所有结点的取值范围为31-233 */
}
