/* 题目要求降序输出不小于X的数 */
/* 故可以把中序遍历逆序得到答案 */
/* 该解法的核心为利用栈实现逆序 */
/* 该解法为中序遍历的递归实现 */
/* 访问内容为维护一个全局的栈 */

int stk[101];
int top;

int C;

void inorder(Tree root)
{
    if (root)
    {
        inorder(root->Left);

        if (root->Element >= C)
        {
            top++;
            stk[top] = root->Element;
        }

        inorder(root->Right);
    }
}

void Print_NLT( Tree T,  int X )
{
    top = -1;
    C = X;
    inorder(T);

    while (top != -1)
    {
        int t = stk[top];
        top--;
        Output(t);
    }
}
