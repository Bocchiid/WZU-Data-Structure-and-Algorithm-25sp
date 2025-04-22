void swap(ElementType *a, ElementType *b)
{
    ElementType temp = *a;
    *a = *b;
    *b = temp;
}
void PercolateUp( int p, PriorityQueue H )
{
    while (p > 1)
    {
        if (H->Elements[p / 2] > H->Elements[p])
        {
            swap(&H->Elements[p / 2], &H->Elements[p]);
            p /= 2;
        }
        else
            break;
    }
}
void PercolateDown( int p, PriorityQueue H )
{
    for (int i = p * 2; i <= H->Size; i *= 2)
    {
        if (i < H->Size && H->Elements[i] > H->Elements[i + 1])
            i++;

        if (H->Elements[i] < H->Elements[p])
        {
            swap(&H->Elements[i], &H->Elements[p]);
            p = i;
        }
        else
            break;
    }
}
