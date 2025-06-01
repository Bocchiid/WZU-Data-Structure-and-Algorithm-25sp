#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    char key[21];
    int cnt;
    struct node *next;
} node;

node *createNode(char key[])
{
    node *s = (node *)malloc(sizeof(node) * 1);
    strcpy(s->key, key);
    s->cnt = 1;
    s->next = NULL;

    return s;
}

int isprime(int x)
{
    int i;

    if (x <= 1)
        return 0;

    for (i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;

    return 1;
}

int minPrime(int x)
{
    int i;

    for (i = x + 1;; i++)
        if (isprime(i))
            return i;
}

int max(int a, int b)
{
    if (a > b)
        return a;

    return b;
}

node *a[200001];

node *find(char key[], int pos)
{
    node *p = a[pos]->next;

    while (p)
    {
        if (strcmp(p->key, key) == 0)
            return p;

        p = p->next;
    }

    return NULL;
}

void insert(char key[], int pos)
{
    node *t = find(key, pos);

    if (t)
        t->cnt++;
    else
    {
        t = createNode(key);
        t->next = a[pos]->next;
        a[pos]->next = t;
    }
}

int main()
{
    int i, j;
    int n;
    /** Input */
    scanf("%d", &n);
    getchar();
    /** Calculate minNextPrime */
    int l = minPrime(n);
    /** Init a */
    for (i = 0; i < l; i++)
        a[i] = createNode("0");
    /** Input keys */
    for (i = 0; i < n; i++)
    {
        char s1[21], s2[21];
        /** Input key */
        scanf("%s %s", s1, s2);
        int pos1, pos2;
        /** Calculate position */
        pos1 = atoll(s1) % l;
        pos2 = atoll(s2) % l;
        /** Insert key */
        insert(s1, pos1);
        insert(s2, pos2);
    }
    /** Get maxt */
    int maxt = 0;

    for (i = 0; i < l; i++)
    {
        node *p = a[i]->next;

        while (p)
        {
            maxt = max(maxt, p->cnt);

            p = p->next;
        }
    }
    /** Get maxt phone number */
    char number[21];
    int flag = 1;

    for (i = 0; i < l; i++)
    {
        node *p = a[i]->next;

        while (p)
        {
            if (p->cnt == maxt)
            {
                if (flag)
                {
                    strcpy(number, p->key);
                    flag = 0;
                }
                else
                {
                    if (strcmp(p->key, number) < 0)
                        strcpy(number, p->key);
                }
            }

            p = p->next;
        }
    }
    /** Output maxt phone number */
    printf("%s %d", number, maxt);
    /** Calculate the number of maxt */
    int cnt = 0;

    for (i = 0; i < l; i++)
    {
        node *p = a[i]->next;

        while (p)
        {
            if (p->cnt == maxt)
                cnt++;

            p = p->next;
        }
    }

    if (cnt != 1)
        printf(" %d", cnt);

    printf("\n");

    return 0;
}
