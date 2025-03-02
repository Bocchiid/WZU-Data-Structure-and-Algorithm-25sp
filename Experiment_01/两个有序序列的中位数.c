// 双指针(快慢指针)解法

#include <stdio.h>

int a[100010];
int b[100010];

int main()
{
    int i;
    int n;
    int slow, fast;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);

    while (slow + fast < (n * 2 - 1) / 2)
    {
        if (a[fast] < b[slow])
            fast++;
        else
            slow++;
    }

    if (a[fast] < b[slow])
        printf("%d\n", a[fast]);
    else
        printf("%d\n", b[slow]);
    
    return 0;
}
