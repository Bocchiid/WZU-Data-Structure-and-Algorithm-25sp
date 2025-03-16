/* 题目描述中的零多项式指的是最后的答案多项式为0, 然后输出0 0 */
/* 该题为PAT乙级原题 */
/* 该解法为与实验目的相匹配的链表解法 */

#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    int a;
    int b;
} data;

typedef struct node
{
    data val;
    struct node* next;
} node;

int main()
{
    data x;
    node *dummy = (node*)malloc(sizeof(node) * 1);
    node *s;
    node *tail = dummy;

    while (scanf("%d %d", &x.a, &x.b) != EOF)
    {
        if (x.b != 0)
        {
            x.a *= x.b;
            x.b -= 1;
            s = (node*)malloc(sizeof(node) * 1);
            s->val = x;
            tail->next = s;
            tail = s;
        }
    }

    node *p;

    p = dummy->next;

    if (dummy->next) // if (p)也行
    {
        while (p)
        {
            if (p != dummy->next)
                printf(" ");

            printf("%d %d", p->val.a, p->val.b);
            p = p->next;
        }
    }
    else
        printf("0 0");
    
    printf("\n");

    return 0;
}
