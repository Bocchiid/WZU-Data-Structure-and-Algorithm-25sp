List MakeEmpty()
{
    List L = (List)malloc(sizeof(struct LNode) * 1);
    L->Last = -1;

    return L;
}

Position Find(List L, ElementType X)
{
    Position i;

    for (i = 0; i <= L->Last; i++)
        if (L->Data[i] == X)
            return i;

    return ERROR;
}

bool Insert(List L, ElementType X, Position P)
{   // P是下标, 我只能说这道题就是神金
    if (L->Last + 1 == MAXSIZE)
    {
        printf("FULL");
        return false;
    }

    if (P < 0 || P > L->Last + 1)
    {
        printf("ILLEGAL POSITION");
        return false;
    }

    Position i;

    for (i = L->Last + 1; i > P; i--)
        L->Data[i] = L->Data[i - 1];

    L->Data[P] = X;
    L->Last++;

    return true;
}

bool Delete(List L, Position P)
{
    if (P < 0 || P > L->Last)
    {
        printf("POSITION %d EMPTY", P);
        return false;
    }

    Position i;

    for (i = P; i < L->Last; i++)
        L->Data[i] = L->Data[i + 1];

    L->Last--;
    
    return true;
}
