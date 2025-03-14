int Delete( int A[], int L, int minA, int maxA )
{
    int i;
    int *a = (int*)malloc(sizeof(int) * L);
    int length = 0;

    for (i = 0; i < L; i++)
        if (A[i] <= minA || A[i] >= maxA)
        {
            a[length] = A[i];
            length++;
        }

    for (i = 0; i < length; i++)
        A[i] = a[i];

    L = length;

    return L;
}
