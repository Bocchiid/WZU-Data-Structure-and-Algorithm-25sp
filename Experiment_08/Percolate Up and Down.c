void PercolateUp( int p, PriorityQueue H )
{
    ElementType x = H->Elements[p];

    while (p > 1)
    {
        if (H->Elements[p / 2] > x)
        {
            H->Elements[p] = H->Elements[p / 2];
            p /= 2;
        }
        else
            break;
    }

    H->Elements[p] = x;
}
void PercolateDown( int p, PriorityQueue H )
{
    ElementType x = H->Elements[p];

    for (int i = p * 2; i <= H->Size; i *= 2)
    {
        if (i < H->Size && H->Elements[i] > H->Elements[i + 1])
            i++;

        if (H->Elements[i] < x)
        {
            H->Elements[p] = H->Elements[i];
            p = i;
        }
        else
            break;
    }

    H->Elements[p] = x;
}
