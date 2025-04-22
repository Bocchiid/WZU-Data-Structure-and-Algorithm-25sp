/* 本题的思路为先构树, 再填值 */
/* 利用BST中序遍历得到的序列是递增序列的特点 */
/* 故该完全二叉树可由中序遍历得到 */
/* 该解法是利用顺序表实现完全二叉树 */

/* 01和02解的区别在于是否将数组作为函数形参 */
/* 02解的实现是将数组作为全局变量 */
/* 该解法的排序实现为快速排序 */

#include <stdio.h>

int n;
int cnt;
int a[1001];
int tree[1001];

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int left, int right)
{
    int pivot = a[left];

    while (left < right)
    {
        while (left < right && a[right] >= pivot)
            right--;

        a[left] = a[right];

        while (left < right && a[left] <= pivot)
            left++;

        a[right] = a[left];
    }

    a[left] = pivot;
    return left;
}

void quickSort(int left, int right)
{
    if (left < right)
    {
        int pivotPos = partition(left, right);
        quickSort(left, pivotPos - 1);
        quickSort(pivotPos + 1, right);
    }
}

void inorder(int root)
{
    if (root > n)
        return;

    inorder(root * 2);

    tree[root] = a[cnt];
    cnt++;

    inorder(root * 2 + 1);
}

int main()
{
    int i;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quickSort(0, n - 1);

    cnt = 0;
    inorder(1);

    for (i = 1; i <= n; i++)
    {
        if (i != 1)
            printf(" ");

        printf("%d", tree[i]);
    }

    printf("\n");

    return 0;
}
