/* 题目要求降序输出不小于X的数 */
/* 故可以把中序遍历逆序得到答案 */
/* 该解法的核心为改造中序遍历为右根左 */
/* 该解法为中序遍历的递归实现 */

void Print_NLT( Tree T,  int X )
{
    if (T)
    {
        Print_NLT(T->Right, X);

        if (T->Element >= X)
            Output(T->Element);
        else
            return; /* 最优性剪枝 */
        
        Print_NLT(T->Left, X);
    }
}
