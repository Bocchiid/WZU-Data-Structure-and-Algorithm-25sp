/* 题目要求降序输出不小于X的数 */
/* 故可以把中序遍历逆序得到答案 */
/* 该解法的核心为利用栈实现逆序 */
/* 该解法为中序遍历的迭代实现 */
/* 访问内容为维护一个栈 */

void Print_NLT( Tree T,  int X )
{
    if (!T) // if (T == NULL)
        return;

    Tree stk[101];
    int top1 = -1;

    Tree p = T;

    int ans[101];
    int top2 = -1;

    while (p || top1 != -1)
    {
        if (p)
        {
            top1++;
            stk[top1] = p;
            p = p->Left;
        }
        else
        {
            p = stk[top1];
            top1--;

            if (p->Element >= X)
            {
                top2++;
                ans[top2] = p->Element;
            }

            p = p->Right;
        }
    }

    while (top2 != -1)
    {
        int t = ans[top2];
        top2--;
        Output(t);
    }
}
