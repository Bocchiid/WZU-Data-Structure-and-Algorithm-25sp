/* 这题注意看主程序中的CreateStack()函数, 注意到S->Top = 0 */
/* 所以, 判空, 判满的条件需要有所改变 */
/*      入栈, 出栈的操作顺序需要有所改变 */

bool Push( Stack S, ElementType X )
{
    if (S->Top == S->MaxSize)
    {
        printf("Stack Full\n");

        return false;
    }

    S->Data[S->Top] = X;
    S->Top++;

    return true;
}
ElementType Pop( Stack S )
{
    if (S->Top == 0)
    {
        printf("Stack Empty\n");

        return ERROR;
    }

    S->Top--;
    ElementType x = S->Data[S->Top];

    return x;
}
