/** 本题没有什么坑, 请放心食用 */

#include <stdio.h>
#include <string.h>

int main()
{
    int i, j;
    int n, m;

    scanf("%d %d", &n, &m);
    getchar();

    for (i = 0; i < n; i++)
    {
        char s[101];

        gets(s);
        /** Make a stack */
        char stk[101];
        int top = -1;

        for (j = 0; j < strlen(s); j++)
        {
            if (s[j] == 'S')
            {
                if (top + 1 == m)
                    break;

                top++;
                s[top] = 'S';
            }
            else if (s[j] == 'X')
            {
                if (top == -1)
                    break;

                top--;
            }
        }

        if (top == -1 && j == strlen(s))
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
