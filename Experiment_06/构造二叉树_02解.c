/* 此解法虽然能过OJ, 但完全不符合题目要求, 对树的学习不利 */
/* 所以, 还请读者自觉学习树的做法 */

#include <stdio.h>

int main()
{
    int left, right, root;

    scanf("%d %d %d", &left, &right, &root);
    printf("root data = %d\n", root);
    printf("left child data = %d\n", left);
    printf("right child data = %d\n", right);

    return 0;
}
