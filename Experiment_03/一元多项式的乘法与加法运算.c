#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    int x;
    int y;
} data;

typedef struct node
{
    data val;
    struct node *next;
} node;

int main()
{
    data x;
    node *l1 = (node*)malloc(sizeof(node) * 1);
    node *l2 = (node*)malloc(sizeof(node) * 1);
    node *s;
    node *t1 = l1;
    node *t2 = l2;
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x.x, &x.y);
        s = (node*)malloc(sizeof(node) * 1);
        s->val = x;
        s->next = NULL;
        t1->next = s;
        t1 = s;
    }

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x.x, &x.y);
        s = (node*)malloc(sizeof(node) * 1);
        s->val = x;
        s->next = NULL;
        t2->next = s;
        t2 = s;
    }

    node *p, *q;
    node *product = (node*)malloc(sizeof(node) * 1);

    p = l1->next;

    while (p)
    {
        q = l2->next;

        while (q)
        {
            data x;

            x.x = p->val.x * q->val.x;
            x.y = p->val.y + q->val.y;

            node *f, *qf;

            qf = product;
            f = product->next; // f = qf->next;

            while (f)
            {
                if (f->val.y <= x.y)
                    break;

                qf = f;
                f = f->next;
            }

            if (qf->next) // if (f)也行
            {
                if (f->val.y == x.y)
                {
                    int sum;

                    sum = f->val.x + x.x;

                    if (sum)
                    {
                        f->val.x += x.x;
                    }
                    else
                    {
                        qf->next = f->next;
                        free(f); // 这句话可以不要
                    }
                }
                else
                {
                    s = (node*)malloc(sizeof(node) * 1);
                    s->val = x;
                    s->next = NULL;
                    s->next = qf->next;
                    qf->next = s;
                }
            }
            else
            {
                s = (node*)malloc(sizeof(node) * 1);
                s->val = x;
                s->next = NULL;
                qf->next = s;
                qf = s;
            }
            
            q = q->next;
        }
        
        p = p->next;
    }

    node *plus = (node*)malloc(sizeof(node) * 1);
    node *tp = plus;

    p = l1->next;
    q = l2->next;

    while (p && q)
    {
        if (p->val.y == q->val.y)
        {
            int sum;

            sum = p->val.x + q->val.x;

            if (sum)
            {
                s = (node*)malloc(sizeof(node) * 1);
                s->val.x = sum;
                s->val.y = p->val.y; // s->val.y == q->val.y;
                s->next = NULL;
                tp->next = s;
                tp = s;
            }

            p = p->next;
            q = q->next;
        }
        else if (p->val.y > q->val.y)
        {
            s = (node*)malloc(sizeof(node) * 1);
            s->val = p->val;
            s->next = NULL;
            tp->next = s;
            tp = s;
            p = p->next;
        }
        else
        {
            s = (node*)malloc(sizeof(node) * 1);
            s->val = q->val;
            s->next = NULL;
            tp->next = s;
            tp = s;
            q = q->next;
        }
    }

    while (p)
    {
        s = (node*)malloc(sizeof(node) * 1);
        s->val = p->val;
        s->next = NULL;
        tp->next = s;
        tp = s;
        p = p->next;
    }

    while (q)
    {
        s = (node*)malloc(sizeof(node) * 1);
        s->val = q->val;
        s->next = NULL;
        tp->next = s;
        tp = s;
        q = q->next;
    }

    p = product->next;

    if (product->next) // if (p)也行
    {
        while (p)
        {
            if (p != product->next)
                printf(" ");

            printf("%d %d", p->val.x, p->val.y);
            p = p->next;
        }
    }
    else
        printf("0 0");

    printf("\n");

    p = plus->next;

    if (plus->next) // if (p)也行
    {
        while (p)
        {
            if (p != plus->next)
                printf(" ");

            printf("%d %d", p->val.x, p->val.y);
            p = p->next;
        }
    }
    else
        printf("0 0");

    printf("\n");

    return 0;
}
