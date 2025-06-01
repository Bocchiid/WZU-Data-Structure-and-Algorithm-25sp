/** 01解和02解的区别在于是否是函数式实现 */
/** 01解为非函数式实现 */

#include <stdio.h>

int main()
{
    int i, j;
    int n, p;

    scanf("%d %d", &n, &p);
    int a[10001];

    for (i = 0; i < 10001; i++)
        a[i] = 0;

    for (i = 0; i < n; i++)
    {
        int num;
        int pos;

        scanf("%d", &num);
        pos = num % p;

        for (j = pos;; j = (j + 1) % p)
        {
            if (a[j] == num)
                break;
            else if (!a[j])
            {
                a[j] = num;
                break;
            }
        }

        if (i != 0)
            printf(" ");

        printf("%d", j);
    }

    printf("\n");

    return 0;
}
