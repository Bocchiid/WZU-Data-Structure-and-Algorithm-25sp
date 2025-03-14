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

    for (i = 1; i < n; i++)
        if (a[i] > a[i - 1])
            length++;
        else
        {
            if (length > maxlength)
                maxlength = length;

            length = 1;
        }

    if (length > maxlength)
        maxlength = length;

    printf("%d\n", maxlength);

    return 0;
}
