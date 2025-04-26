/* 该解法为对权值直接构非叶子结点 */
/* 该解法的calWPL为sum += 非叶子结点权值实现 */

#include <stdio.h>

int a[20001];
int count;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void initPQ()
{
    count = 1;
}

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

void Insert(int val)
{
    a[count] = val;
    percolateUp(count);
    count++;
}

void percolateDown(int p)
{
    for (int i = p * 2; i <= count; i *= 2)
    {
        if (i < count && a[i] > a[i + 1])
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

int Delete()
{
    int res = a[1];

    count--;
    a[1] = a[count];
    percolateDown(1);

    return res;
}

int main()
{
    int i, j;
    int n;
    int num;

    initPQ();
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &num);
        Insert(num);
    }

    int m1, m2;
    int sum = 0;

    while (count - 1 > 1)
    {
        m1 = Delete();
        m2 = Delete();

        Insert(m1 + m2);
        sum += m1 + m2;
    }

    printf("%d\n", sum);

    return 0;
}
