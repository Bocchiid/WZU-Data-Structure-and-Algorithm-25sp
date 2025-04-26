/* 该解法的isprefix为暴力枚举 + 朴素匹配 */

/* 该解法的selectTwoMin的实现为顺序查找 */
/* 该解法的calWPL为sum += 非叶子结点权值实现 */

#include <stdio.h>
#include <string.h>

typedef struct tnode
{
    int weight;
    int parent;
    int left;
    int right;
} tnode;

void init(int w[], tnode a[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        a[i].weight = w[i];
        a[i].parent = -1;
        a[i].left = a[i].right = -1;
    }

    for (i; i < 2 * size - 1; i++)
    {
        a[i].parent = -1;
        a[i].left = a[i].right = -1;
    }
}

void selectTwoMin(tnode a[], int size, int *m1, int *m2)
{
    int i;
    int first = 1;
    int second = 1;

    for (i = 0; i < size; i++)
    {
        if (a[i].parent == -1)
        {
            if (first)
            {
                *m1 = i;
                first = 0;
            }
            else
            {
                if (second)
                {
                    *m2 = i;
                    second = 0;
                }

                if (a[i].weight < a[*m1].weight)
                {
                    *m2 = *m1;
                    *m1 = i;
                }
                else if (a[i].weight < a[*m2].weight)
                    *m2 = i;
            }
        }
    }
}

void buildTree(tnode a[], int size, int *sum)
{
    int i;
    int m1, m2;

    for (i = size; i < 2 * size - 1; i++)
    {
        selectTwoMin(a, i, &m1, &m2);

        a[i].weight = a[m1].weight + a[m2].weight;
        a[i].left = m1;
        a[i].right = m2;

        a[m1].parent = i;
        a[m2].parent = i;
        *sum += a[i].weight;
    }
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
    char c;

    scanf("%d\n", &n);
    int w[10001];

    for (i = 0; i < n; i++)
        scanf("%c %d ", &c, &w[i]);

    tnode a[20001];
    init(w, a, n);

    int sum = 0;
    buildTree(a, n, &sum);

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
