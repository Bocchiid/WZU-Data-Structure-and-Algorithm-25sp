#include <stdio.h>

int main()
{
    int i;
    int k;
    int a;
    int thissum = 0;
    int maxsum = 0;

    scanf("%d", &k);

    for (i = 0; i < k; i++)
    {
        scanf("%d", &a);
        
        if (thissum + a > a)
        {
            thissum += a;
        }
        else
        {
            thissum = a;
        }

        if (thissum > maxsum)
        {
            maxsum = thissum;
        }
    }

    printf("%d\n", maxsum);
}
