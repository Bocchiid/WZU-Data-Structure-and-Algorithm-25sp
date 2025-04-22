/* 由于二叉堆不唯一 */
/* 本题请严格按照percolateDown(下滤/下沉)调整建立二叉堆 */
/* 01和02解的区别在于是否将数组作为函数形参 */
/* 02解的实现是将数组作为全局变量 */

/* 注: percolateDown为函数6-1的02解实现 */

#include <stdio.h>

int a[1001];
int n;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void percolateDown(int k)
{
    for (int i = k * 2; i <= n; i *= 2)
    {
        if (i < n && a[i] > a[i + 1])
            i++;

        if (a[i] < a[k])
        {
            swap(&a[i], &a[k]);
            k = i;
        }
        else
            break;
    }
}

int main()
{
    int i;
    int c;

    scanf("%d", &c);
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (i = n / 2; i >= 1; i--)
        percolateDown(i);

    for (i = 1; i <= n; i++)
        printf("%d\n", a[i]);

    return 0;
}
