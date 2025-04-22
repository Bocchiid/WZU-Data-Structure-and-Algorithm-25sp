/* 由于二叉堆不唯一 */
/* 本题请严格按照percolateDown(下滤/下沉)调整建立二叉堆 */
/* 01和02解的区别在于是否将数组作为函数形参 */
/* 01解的实现是将数组作为形参处理 */

/* 注: percolateDown为函数6-1的02解实现 */

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void percolateDown(int a[], int k, int size)
{
    for (int i = k * 2; i <= size; i *= 2)
    {
        if (i < size && a[i] > a[i + 1])
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
    int n;

    scanf("%d", &c);
    scanf("%d", &n);
    int a[1001] = {0};

    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (i = n / 2; i >= 1; i--)
        percolateDown(a, i, n);

    for (i = 1; i <= n; i++)
        printf("%d\n", a[i]);

    return 0;
}
