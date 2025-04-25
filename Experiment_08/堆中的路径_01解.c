/* 由于二叉堆不唯一 */
/* 本题请严格按照percolateUp(上滤/上升)调整建立二叉堆 */
/* 01和02解的区别在于是否将数组作为函数形参 */
/* 01解的实现是将数组作为函数形参 */

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/* percolateUp()为6-1的02解实现 */
void percolateUp(int a[], int p)
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

void print(int a[], int p)
{
    int flag = 1; /* 用于格式控制 */
    
    while (p >= 1)
    {
        if (!flag)
            printf(" ");

        printf("%d", a[p]);
        flag = 0;
        p /= 2;
    }

    printf("\n");
}

int main()
{
    int i, j;
    int n, m;

    scanf("%d %d", &n, &m);
    int a[1001];

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        percolateUp(a, i);
    }

    int num;

    for (i = 0; i < m; i++)
    {
        scanf("%d", &num);
        print(a, num);
    }

    return 0;
}
