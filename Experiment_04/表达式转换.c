/** 本题的坑在于: 输入里面存在小数和负数 */

#include <stdio.h>
#include <string.h>

int main()
{
    int i, j;
    char s[101];

    gets(s);
    /** Make a stack */
    char stk[101];
    int top = -1;
    /** 用于格式控制 */
    int flag = 1;

    for (i = 0; i < strlen(s); i++)
    {
        if (i == 0 && s[i] == '-')
        {
            char s1[101];
            int length = 0;

            s1[length] = '-';
            length++;

            for (j = i + 1; j < strlen(s) && (s[j] >= '0' && s[j] <= '9' || s[j] == '.'); j++)
            {
                s1[length] = s[j];
                length++;
            }

            s1[length] = '\0';

            if (!flag)
                printf(" ");

            printf("%s", s1);
            flag = 0;

            i = j - 1;
        }
        else if (i > 0 && i < strlen(s) - 2 &&
                 (s[i] == '-' || s[i] == '+') &&
                 s[i - 1] == '(' && s[i + 1] >= '0' && s[i + 1] <= '9')
        {
            char s1[101];
            int length = 0;

            if (s[i] == '-')
            {
                s1[length] = '-';
                length++;
            }

            for (j = i + 1; j < strlen(s) && (s[j] >= '0' && s[j] <= '9' || s[j] == '.'); j++)
            {
                s1[length] = s[j];
                length++;
            }

            s1[length] = '\0';

            if (!flag)
                printf(" ");

            printf("%s", s1);
            flag = 0;

            i = j;
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            char s1[101];
            int length = 0;

            for (j = i; j < strlen(s) && (s[j] >= '0' && s[j] <= '9' || s[j] == '.'); j++)
            {
                s1[length] = s[j];
                length++;
            }

            s1[length] = '\0';

            if (!flag)
                printf(" ");

            printf("%s", s1);
            flag = 0;

            i = j - 1;
        }
        else if (s[i] == '(' && i < strlen(s) - 1 && s[i + 1] != '+' && s[i + 1] != '-')
        {
            top++;
            stk[top] = s[i];
        }
        else if (s[i] == ')')
        {
            while (top != -1 && stk[top] != '(')
            {
                if (!flag)
                    printf(" ");

                printf("%c", stk[top]);
                flag = 0;
                top--;
            }

            top--;
        }
        else if (s[i] == '+' || s[i] == '-')
        {
            while (top != -1 && stk[top] != '(')
            {
                if (!flag)
                    printf(" ");

                printf("%c", stk[top]);
                flag = 0;
                top--;
            }

            top++;
            stk[top] = s[i];
        }
        else if (s[i] == '*' || s[i] == '/')
        {
            while (top != -1 && stk[top] != '(' &&
                   stk[top] != '+' && stk[top] != '-')
            {
                if (!flag)
                    printf(" ");

                printf("%c", stk[top]);
                flag = 0;
                top--;
            }

            top++;
            stk[top] = s[i];
        }
    }

    while (top != -1)
    {
        if (!flag)
            printf(" ");

        printf("%c", stk[top]);
        flag = 0;
        top--;
    }

    return 0;
}
