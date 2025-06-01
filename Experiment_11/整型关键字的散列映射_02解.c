/** 01解和02解的区别在于是否是函数式实现 */
/** 02解为函数式实现 */

#include <stdio.h>

int find(int a[], int p, int num)
{
    int i;
    int pos = num % p;

    for (i = pos;; i = (i + 1) % p)
    {
        if (a[i] == num)
            return i;
        else if (!a[i])
            return i;
    }
}

int insert(int a[], int p, int num)
{
    int pos = find(a, p, num);

    if (!a[pos])
        a[pos] = num;

    return pos;
}

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
        pos = insert(a, p, num);

        if (i != 0)
            printf(" ");

        printf("%d", pos);
    }

    printf("\n");

    return 0;
}
