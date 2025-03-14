List Delete( List L, ElementType minD, ElementType maxD )
{
    Position slow, fast;

    slow = fast = 0;

    while (fast <= L->Last)
    {
        if (L->Data[fast] <= minD || L->Data[fast] >= maxD)
        {
            L->Data[slow] = L->Data[fast];
            slow++;
        }

        fast++;
    }

    L->Last = slow - 1;

    return L;
}
