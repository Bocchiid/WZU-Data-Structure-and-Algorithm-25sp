int FactorialSum( List L )
{
    int sum = 0;
    int res;
    List p;

    p = L;

    while (p)
    {
        res = 1;

        for (int i = 1; i <= p->Data; i++)
            res *= i;

        sum += res;
        p = p->Next;
    }

    return sum;
}
