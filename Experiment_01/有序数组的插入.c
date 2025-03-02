bool Insert( List L, ElementType X )
{
    if (L->Last + 1 == MAXSIZE)
        return false;

    int i;
    int pos = 0;

    for (i = 0; i <= L->Last; i++)
        if (L->Data[i] == X)
            return false;
        else if (L->Data[i] > X)
            pos = i + 1;
    
    for (i = L->Last + 1; i > pos; i--)
        L->Data[i] = L->Data[i - 1];

    L->Data[pos] = X;
    L->Last++;
    
    return true;
}
