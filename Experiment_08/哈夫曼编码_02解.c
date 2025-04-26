/* 该解法的isprefix为暴力枚举 + 朴素匹配 */

/* 该解法的selectTwoMin的实现为堆排序 */
/* 该解法的calWPL为sum += 非叶子结点权值实现 */

#include <stdio.h>
#include <string.h>

typedef struct tnode
{
    int weight;
    int parent;
    int left;
    int right;
    int idx;
} tnode;

tnode pq[10001];
int count;

void swap(tnode *a, tnode *b)
{
    tnode temp = *a;
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
        if (pq[p / 2].weight > pq[p].weight)
        {
            swap(&pq[p / 2], &pq[p]);
            p /= 2;
        }
        else
            break;
    }
}

void Insert(tnode val)
{
    pq[count] = val;
    percolateUp(count);
    count++;
}

void percolateDown(int p)
{
    int i;

    for (i = p * 2; i <= count; i *= 2)
    {
        if (i < count && pq[i].weight > pq[i + 1].weight)
            i++;

        if (pq[i].weight < pq[p].weight)
        {
            swap(&pq[i], &pq[p]);
            p = i;
        }
        else
            break;
    }
}

tnode Delete()
{
    tnode res = pq[1];

    count--;
    pq[1] = pq[count];
    percolateDown(1);

    return res;
}

void init(int w[], tnode a[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        a[i].weight = w[i];
        a[i].parent = -1;
        a[i].left = a[i].right = -1;
        a[i].idx = i;

        Insert(a[i]);
    }

    for (i; i < 2 * size - 1; i++)
    {
        a[i].parent = -1;
        a[i].left = a[i].right = -1;
    }
}

void selectTwoMin(tnode *m1, tnode *m2)
{
    *m1 = Delete();
    *m2 = Delete();
}

void buildTree(tnode a[], int size, int *sum)
{
    int i;
    tnode m1, m2;

    for (i = size; i < 2 * size - 1; i++)
    {
        selectTwoMin(&m1, &m2);

        a[i].weight = m1.weight + m2.weight;
        a[i].left = m1.idx;
        a[i].right = m2.idx;
        a[i].idx = i;

        a[m1.idx].parent = i;
        a[m2.idx].parent = i;

        Insert(a[i]);
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

    initPQ();

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
