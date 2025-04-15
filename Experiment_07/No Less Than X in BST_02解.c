/* 题目要求降序输出不小于X的数 */
/* 故可以把中序遍历逆序得到答案 */
/* 该解法的核心为改造中序遍历为右根左 */
/* 该解法为中序遍历的迭代实现 */

void Print_NLT( Tree T,  int X )
{
    if (!T) // if (T)
        return;

    Tree stk[101];
    int top = -1;

    Tree p = T;

    while (p || top != -1)
    {
        if (p)
        {
            top++;
            stk[top] = p;
            p = p->Right;
        }
        else
        {
            p = stk[top];
            top--;

            if (p->Element >= X)
                Output(p->Element);

            p = p->Left;
        }
    }
}
