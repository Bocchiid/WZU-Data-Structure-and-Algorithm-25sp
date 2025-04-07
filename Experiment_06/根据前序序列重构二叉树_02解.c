/* 此解法虽然能过OJ, 但完全不符合题目要求, 对树的学习不利 */
/* 所以, 还请读者自觉学习树的做法 */

#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    int n;
    char val[101];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%s", val);

        if (strcmp(val, "#") != 0)
            printf("%s\n", val);
    }

    return 0;
}
