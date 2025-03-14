/* 条件筛法 */

List Delete( List L, ElementType minD, ElementType maxD )
{
    Position i;
    Position *l = (Position*)malloc(sizeof(Position) * (L->Last + 1));
    Position length = 0;

    for (i = 0; i <= L->Last; i++)
        if (L->Data[i] <= minD || L->Data[i] >= maxD)
        {
            l[length] = L->Data[i];
            length++;
        }

    for (i = 0; i < length; i++)
        L->Data[i] = l[i];

    L->Last = length - 1;

    return L;
}
