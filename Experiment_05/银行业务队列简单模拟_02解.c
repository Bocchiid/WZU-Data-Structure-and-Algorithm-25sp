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

    int flag = 1;

    while (head1 - tail1 != 0 || head2 - tail2 != 0)
    {
        if (head1 - tail1 != 0)
        {
            if (flag)
            {
                printf("%d", a[head1]);
                flag = 0;
            }
            else
                printf(" %d", a[head1]);

            head1++;
        }

        if (head1 - tail1 != 0)
        {
            printf(" %d", a[head1]);
            head1++;
        }

        if (head2 - tail2 != 0)
        {
            if (flag)
            {
                printf("%d", b[head2]);
                flag = 0;
            }
            else
                printf(" %d", b[head2]);

            head2++;
        }
    }

    printf("\n");

    return 0;
}
