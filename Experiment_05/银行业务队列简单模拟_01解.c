#include <stdio.h>

int main()
{
    int i, j;
    int n;

    scanf("%d", &n);

    int a[1001];
    int head1 = 0;
    int tail1 = 0;

    int b[1001];
    int head2 = 0;
    int tail2 = 0;

    for (i = 0; i < n; i++)
    {
        int num;

        scanf("%d", &num);

        if (num & 1 == 1)
        {
            a[tail1] = num;
            tail1++;
        }
        else
        {
            b[tail2] = num;
            tail2++;
        }
    }

    int ans[1001];
    int size = 0;

    while (head1 - tail1 != 0 || head2 - tail2 != 0)
    {
        if (head1 - tail1 != 0)
        {
            ans[size] = a[head1];
            head1++;
            size++;
        }

        if (head1 - tail1 != 0)
        {
            ans[size] = a[head1];
            head1++;
            size++;
        }

        if (head2 - tail2 != 0)
        {
            ans[size] = b[head2];
            head2++;
            size++;
        }
    }

    for (i = 0; i < size; i++)
    {
        if (i != 0)
            printf(" ");

        printf("%d", ans[i]);
    }

    printf("\n");

    return 0;
}
