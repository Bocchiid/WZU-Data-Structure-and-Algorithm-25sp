#include <stdio.h>

int a[100010];

int main()
{
    int i;
    int n;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int length = 1;
    int maxlength = 1;
    int start = 0;

    for (i = 1; i < n; i++)
        if (a[i] > a[i - 1])
            length++;
        else
        {
            if (length > maxlength)
            {
                maxlength = length;
                start = i - maxlength;
            }

            length = 1;
        }

    if (length > maxlength)
    {
        maxlength = length;
        start = i - maxlength;
    }

    for (i = start; i < start + maxlength; i++)
    {
        if (i != start)
            printf(" ");

        printf("%d", a[i]);
    }

    return 0;
}
