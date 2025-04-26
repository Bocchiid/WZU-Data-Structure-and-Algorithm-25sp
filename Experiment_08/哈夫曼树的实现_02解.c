/* 该解法的selectTwoMin的实现为堆排序 */
/* 该解法的calWPL为sum += 非叶子结点权值实现 */

#include <stdio.h>

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

int main()
{
    int i, j;
    int n;

    scanf("%d", &n);
    int w[10001];

    for (i = 0; i < n; i++)
        scanf("%d", &w[i]);

    initPQ();

    tnode a[20001];
    init(w, a, n);

    int sum = 0;
    buildTree(a, n, &sum);
    printf("%d\n", sum);

    return 0;
}
