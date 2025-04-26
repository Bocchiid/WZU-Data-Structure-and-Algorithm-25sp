/* 该解法的selectTwoMin的实现为顺序查找 */
/* 该解法的calWPL为sum += weight * length 实现 */

#include <stdio.h>

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

    for (i; i <= 2 * size - 1; i++)
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

void buildTree(tnode a[], int size)
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
    }
}

int calWPL(tnode a[], int size)
{
    int i;
    int sum = 0;
    int p;
    int length;

    for (i = 0; i < size; i++)
    {
        length = 0;
        p = i;

        while (a[p].parent != -1)
        {
            length++;
            p = a[p].parent;
        }

        sum += a[i].weight * length;
    }

    return sum;
}

int main()
{
    int i, j;
    int n;

    scanf("%d", &n);
    int w[10001];

    for (i = 0; i < n; i++)
        scanf("%d", &w[i]);

    tnode a[20001];
    init(w, a, n);

    buildTree(a, n);

    int sum = 0;
    sum = calWPL(a, n);
    printf("%d\n", sum);

    return 0;
}
