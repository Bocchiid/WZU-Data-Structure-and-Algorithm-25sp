/** 01解和02解的区别在于是否是函数式实现 */
/** 01解为非函数式实现 */

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
        pos = num % l;
        cnt = 0;

        for (j = pos; cnt != l; j = (pos + cnt * cnt) % l)
        {
            if (!a[j])
            {
                a[j] = num;
                break;
            }

            cnt++;
        }

        if (i != 0)
            printf(" ");

        if (cnt != l)
            printf("%d", j);
        else
            printf("-");
    }

    printf("\n");

    return 0;
}
