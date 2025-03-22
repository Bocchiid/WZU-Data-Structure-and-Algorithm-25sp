/* 本题的测试样例跑出来是超时的, 所以不要管测试样例, 直接提交就行了 */

Stack CreateStack( int MaxSize )
{
    Stack S = (Stack)malloc(sizeof(struct SNode) * 1);
    S->MaxSize = MaxSize;
    S->Data = (ElementType*)malloc(sizeof(ElementType) * S->MaxSize);
    S->Top1 = -1;
    S->Top2 = S->MaxSize;

    return S;
}
bool Push( Stack S, ElementType X, int Tag )
{
    if (S->Top1 + 1 == S->Top2)
    {
        printf("Stack Full\n");

        return false;
    }

    if (Tag == 1)
    {
        S->Top1++;
        S->Data[S->Top1] = X;
    }
    else if (Tag == 2) // else
    {
        S->Top2--;
        S->Data[S->Top2] = X;
    }

    return true;
}
ElementType Pop( Stack S, int Tag )
{
    if (Tag == 1)
    {
        if (S->Top1 == -1)
        {
            printf("Stack %d Empty\n", Tag);

            return ERROR;
        }

        ElementType x = S->Data[S->Top1];
        S->Top1--;

        return x;
    }
    else if (Tag == 2) // else
    {
        if (S->Top2 == S->MaxSize)
        {
            printf("Stack %d Empty\n", Tag);

            return ERROR;
        }

        ElementType x = S->Data[S->Top2];
        S->Top2++;

        return x;
    }
}
