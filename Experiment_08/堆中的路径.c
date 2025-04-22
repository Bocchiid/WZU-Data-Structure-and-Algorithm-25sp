/* 由于二叉堆不唯一 */
/* 本题请严格按照percolateUp(上滤/上升)调整建立二叉堆 */

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void percolateUp(int a[], int k)
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

void print(int a[], int k)
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
    int a[1001] = {0};

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
