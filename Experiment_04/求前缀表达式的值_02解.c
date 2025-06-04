/** 本题的坑在于: 输入可能存在负数和小数 */

/** 01和02解的区别在于是否是函数式实现 */
/** 02解为函数式实现 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/** Make a stack */
double stk[101];
int top = -1;

double a, b;

int isvalid()
{
    if (top < 1)
    {
        printf("ERROR\n");

        return 0;
    }

    return 1;
}

void getTwoNum()
{
    a = stk[top];
    top--;
    b = stk[top];
    top--;
}

int main()
{
    int i, j;
    char s[101];

    gets(s);

    for (i = strlen(s) - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            char s1[101];
            int length = 101;

            length--;
            s1[length] = '\0';

            for (j = i; j >= 0 && (s[j] >= '0' && s[j] <= '9' || s[j] == '.'); j--)
            {
                length--;
                s1[length] = s[j];
            }

            if (j >= 0 && s[j] == '-')
            {
                length--;
                s1[length] = s[j];
            }

            char *p = &s1[length];

            top++;
            stk[top] = atof(p);

            i = j;
        }
        else if (s[i] == '+')
        {
            if (!isvalid())
                return 0;

            getTwoNum();

            top++;
            stk[top] = a + b;
        }
        else if (s[i] == '-')
        {
            if (!isvalid())
                return 0;

            getTwoNum();

            top++;
            stk[top] = a - b;
        }
        else if (s[i] == '*')
        {
            if (!isvalid())
                return 0;

            getTwoNum();

            top++;
            stk[top] = a * b;
        }
        else if (s[i] == '/')
        {
            if (!isvalid())
                return 0;

            getTwoNum();

            if (b == 0)
            {
                printf("ERROR\n");

                return 0;
            }

            top++;
            stk[top] = a / b;
        }
    }

    if (top == 0)
    {
        printf("%.1f\n", stk[top]);
        top--;
    }
    else
        printf("ERROR\n");

    return 0;
}
