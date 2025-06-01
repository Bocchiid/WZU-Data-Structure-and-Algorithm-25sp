/** 01解和02解的区别在于是否是函数式实现 */
/** 01解为非函数式实现 */

#include <stdio.h>

int main()
{
    int i, j;
    int l;
    int n;

    scanf("%d", &l);
    int a[101];

    for (i = 0; i < 101; i++)
        a[i] = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        int num;
        int pos;

        scanf("%d", &num);
        pos = num % l;

        for (j = pos;; j = (j + 1) % l)
        {
            if (a[j] == num)
                break;
            else if (!a[j])
            {
                a[j] = num;
                break;
            }
        }
    }

    for (i = 0; i < l; i++)
        if (a[i])
            printf("ht[%d] = %d\n", i, a[i]);

    return 0;
}
