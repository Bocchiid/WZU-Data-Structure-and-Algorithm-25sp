/** 01解和02解的区别在于是否是函数式实现 */
/** 02解为函数式实现 */

#include <stdio.h>

int find(int a[], int l, int num)
{
    int i;
    int pos = num % l;

    for (i = pos;; i = (i + 1) % l)
    {
        if (a[i] == num)
            return -1;
        else if (!a[i])
            return i;
    }
}

void insert(int a[], int l, int num)
{
    int pos = find(a, l, num);

    if (pos != -1)
        a[pos] = num;
}

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
        insert(a, l, num);
    }

    for (i = 0; i < l; i++)
        if (a[i])
            printf("ht[%d] = %d\n", i, a[i]);

    return 0;
}
