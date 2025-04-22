/* 由于二叉堆不唯一 */
/* 本题请严格按照percolateUp(上滤/上升)调整建立二叉堆 */
/* 01和02解的区别在于是否将数组作为函数形参 */
/* 02解的实现是将数组作为全局变量 */

#include <stdio.h>

int a[1001];

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void percolateUp(int k)
{
    while (k > 1)
    {
        if (a[k / 2] > a[k])
        {
            swap(&a[k / 2], &a[k]);
            k /= 2;
        }
        else
            break;
    }
}

void print(int k)
{
    int flag = 1;

    while (k >= 1)
    {
        if (!flag)
            printf(" ");

        printf("%d", a[k]);
        k /= 2;
        flag = 0;
    }

    printf("\n");
}

int main()
{
    int i;
    int n, m;

    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        percolateUp(i);
    }

    int num;

    for (i = 0; i < m; i++)
    {
        scanf("%d", &num);
        print(num);
    }

    return 0;
}
