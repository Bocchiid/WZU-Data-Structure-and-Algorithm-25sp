/** 01解和02解的区别在于是否是函数式实现 */
/** 02解为函数式实现 */

#include <stdio.h>

int isprime(int x)
{
    int i;

    if (x <= 1)
        return 0;

    for (i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;

    return 1;
}

int minPrime(int x)
{
    int i;

    for (i = x + 1;; i++)
        if (isprime(i))
            return i;
}

int find(int a[], int l, int num, int *cnt)
{
    int i;
    int pos = num % l;
    *cnt = 0;

    for (i = pos; *cnt != l; i = (pos + (*cnt) * (*cnt)) % l)
    {
        if (!a[i])
            break;

        (*cnt)++;
    }

    return i;
}

void insert(int a[], int l, int num, int *pos, int *cnt)
{
    *pos = find(a, l, num, cnt);

    if (*cnt != l)
        a[*pos] = num;
}

int main()
{
    int i, j;
    int MSize, N;

    scanf("%d %d", &MSize, &N);
    int l = minPrime(MSize);
    int a[100001];

    for (i = 0; i < l; i++)
        a[i] = 0;

    for (i = 0; i < N; i++)
    {
        int num;
        int pos;
        int cnt;

        scanf("%d", &num);
        insert(a, l, num, &pos, &cnt);

        if (i != 0)
            printf(" ");

        if (cnt != l)
            printf("%d", pos);
        else
            printf("-");
    }

    printf("\n");

    return 0;
}
