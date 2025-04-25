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
/* percolateUp()为6-1的02解实现 */
void percolateUp(int p)
{
    while (p > 1)
    {
        if (a[p / 2] > a[p])
        {
            swap(&a[p / 2], &a[p]);
            p /= 2;
        }
        else
            break;
    }
}
/* percolateDown()为6-1的02解实现 */
void percolateDown(int p, int size)
{
    for (int i = p * 2; i <= size; i *= 2)
    {
        if (i < size && a[i] > a[i + 1])
            i++;

        if (a[i] < a[p])
        {
            swap(&a[i], &a[p]);
            p = i;
        }
        else
            break;
    }
}

void Delete(int *size)
{
    a[1] = a[*size];
    (*size)--;

    percolateDown(1, *size);
}

int main()
{
    int i, j;
    int c;
    int n;

    scanf("%d", &c);
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        percolateUp(i);
    }

    int x;
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
