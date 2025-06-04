/** 本题没有什么坑, 请放心食用 */

/** 01和02解的区别在于是否是函数式实现 */
/** 02解为函数式实现 */

#define ERROR 1000000000

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/** Make a stack */
int stk[1001];
int top = -1;

int a, b;

int isvalid()
{
    if (top < 1)
    {
        printf("错误：表达式不规范。\n");
        printf("%d\n", ERROR);

        return 0;
    }

    return 1;
}

void getTwoNum()
{
    b = stk[top];
    top--;
    a = stk[top];
    top--;
}

int main()
{
    int i, j;
    char s[1001];

    while (scanf("%s", s) != EOF)
    {
        if (strcmp(s, "+") == 0)
        {
            if (!isvalid())
                return 0;

            getTwoNum();

            top++;
            stk[top] = a + b;
        }
        else if (strcmp(s, "-") == 0)
        {
            if (!isvalid())
                return 0;

            getTwoNum();

            top++;
            stk[top] = a - b;
        }
        else if (strcmp(s, "*") == 0)
        {
            if (!isvalid())
                return 0;

            getTwoNum();

            top++;
            stk[top] = a * b;
        }
        else if (strcmp(s, "/") == 0)
        {
            if (!isvalid())
                return 0;

            getTwoNum();

            if (b == 0)
            {
                printf("错误：除法操作分母为零。\n");
                printf("%d\n", ERROR);

                return 0;
            }

            top++;
            stk[top] = a / b;
        }
        else if (strcmp(s, "%") == 0)
        {
            if (!isvalid())
                return 0;

            getTwoNum();

            if (b == 0)
            {
                printf("错误：取模操作除数为零。\n");
                printf("%d\n", ERROR);

                return 0;
            }

            top++;
            stk[top] = a % b;
        }
        else
        { /** Transform string into int and push it to stack */
            top++;
            stk[top] = atoi(s);
        }
    }

    if (top == 0)
    {
        printf("%d\n", stk[top]);
        top--;
    }
    else
    {
        printf("错误：表达式不规范。\n");
        printf("%d\n", ERROR);
    }

    return 0;
}
