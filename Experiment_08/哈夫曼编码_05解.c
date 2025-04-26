/* 该解法的isprefix为暴力枚举 + 朴素匹配 */

/* 该解法为对权值直接构非叶子结点 */
/* 该解法的calWPL为sum += 非叶子结点权值实现 */

#include <stdio.h>
#include <string.h>

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

int calWPL1(int w[], char b[][64], int size)
{
    int i;
    int sum1 = 0;

    for (i = 0; i < size; i++)
        sum1 += w[i] * strlen(b[i]);

    return sum1;
}

int isprefix(char b[][64], int size)
{
    int i, j;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (i == j)
                continue;

            if (strlen(b[i]) > strlen(b[j]))
                continue;

            if (strstr(b[j], b[i]) == b[j])
                return 0;
        }
    }

    return 1;
}

int main()
{
    int i, j;
    int n;
    int num;
    char c;

    initPQ();
    scanf("%d\n", &n);
    int w[10001];

    for (i = 0; i < n; i++)
    {
        scanf("%c %d ", &c, &w[i]);
        Insert(w[i]);
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

    int m;
    scanf("%d\n", &m);
    int sum1;

    for (i = 0; i < m; i++)
    {
        char b[10001][64] = {0};

        for (j = 0; j < n; j++)
            scanf("%c %s\n", &c, b[j]);

        sum1 = calWPL1(w, b, n);

        if (sum != sum1)
        {
            printf("No\n");
            continue;
        }

        if (isprefix(b, n))
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
