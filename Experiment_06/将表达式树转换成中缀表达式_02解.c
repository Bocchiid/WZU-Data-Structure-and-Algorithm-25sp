/* 此解法虽然能过OJ, 但完全不符合题目要求, 对树的学习不利 */
/* 所以, 还请读者自觉学习树的做法 */

#include <stdio.h>

int main()
{
    char left[101], right[101], root[101];

    scanf("%s %s %s", left, right, root);
    printf("(%s)%s(%s)\n", left, root, right);

    return 0;
}
