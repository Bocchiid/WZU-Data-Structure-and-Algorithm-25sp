/** 本题的坑在于: 没有坑 */
/** 单纯就是处理起来比较麻烦 */

#include <stdio.h>
#include <string.h>

int main()
{
    int i, j;
    char s[10001];

    gets(s);
    /** Make a stack */
    char stk[10001];
    int top = -1;

    while (strcmp(s, ".") != 0)
    {
        for (i = 0; i < strlen(s); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                top++;
                stk[top] = s[i];
            }
            else if (s[i] == '/')
            {
                if (i < strlen(s) - 1 && s[i + 1] == '*')
                {
                    top++;
                    stk[top] = s[i];

                    i++;
                    top++;
                    stk[top] = s[i];
                }
            }
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if (top == -1)
                {
                    printf("NO\n");
                    printf("?-%c\n", s[i]);

                    return 0;
                }
                else
                {
                    char c = stk[top];
                    top--;

                    if (c == '(' && s[i] != ')' ||
                        c == '[' && s[i] != ']' ||
                        c == '{' && s[i] != '}' ||
                        c == '*')
                    {
                        if (c != '*')
                        {
                            printf("NO\n");
                            printf("%c-?\n", c);

                            return 0;
                        }
                        else
                        {
                            printf("NO\n");
                            printf("/*-?\n");

                            return 0;
                        }
                    }
                }
            }
            else if (s[i] == '*')
            {
                if (i < strlen(s) - 1 && s[i + 1] == '/')
                {
                    if (top == -1)
                    {
                        printf("NO\n");
                        printf("?-*/\n");

                        return 0;
                    }
                    else
                    {
                        char c = stk[top];
                        top--;

                        if (c == '*')
                        {
                            i++;
                            top--;
                        }
                        else
                        {
                            printf("NO\n");
                            printf("%c-?\n", c);

                            return 0;
                        }
                    }
                }
            }
        }

        gets(s);
    }

    if (top == -1)
        printf("YES\n");
    else
    {
        char c = stk[top];
        top--;

        if (c == '*')
        {
            printf("NO\n");
            printf("/*-?\n");
        }
        else
        {
            printf("NO\n");
            printf("%c-?\n", c);
        }
    }

    return 0;
}
