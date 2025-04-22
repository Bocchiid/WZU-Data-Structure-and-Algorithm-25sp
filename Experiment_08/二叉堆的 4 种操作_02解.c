/* 由于二叉堆不唯一 */
/* 本题请严格按照percolateDown(下滤/下沉)调整建立二叉堆 */
/* 01和02解的区别在于是否将数组作为函数形参 */
/* 02解的实现是将数组作为全局变量 */

/* 注: percolateUp为函数6-1的02解实现 */
/* 注: percolateDown为函数6-1的02解实现 */

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

void percolateDown(int k, int size)
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

void Delete(int *size)
{
    a[1] = a[*size];
    (*size)--;

    for (int i = *size / 2; i >= 1; i--)
        percolateDown(i, *size);
}

int main()
{
    int i;
    int c;
    int n;
    int x;

    scanf("%d", &c);
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &x);
    n++;
    a[n] = x;
    percolateUp(n);

    printf("min = %d\n", a[1]);
    Delete(&n);

    for (i = 1; i <= n; i++)
        printf("%d\n", a[i]);

    return 0;
}
