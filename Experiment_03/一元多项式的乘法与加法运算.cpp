#include <iostream>
using namespace std;

struct item
{
    int x;
    int y;
};

struct node
{
    item val;
    node *next;

    node()
    {
        val.x = 0;
        val.y = 0;
        next = nullptr;
    }

    node(int x, int y)
    {
        val.x = x;
        val.y = y;
        next = nullptr;
    }
};

int main()
{
    node *l1 = new node();
    node *l2 = new node();
    int i;
    int n;
    int x, y;
    node *s;
    node *tail1 = l1;
    node *tail2 = l2;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        s = new node(x, y);
        tail1->next = s;
        tail1 = s;
    }

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        s = new node(x, y);
        tail2->next = s;
        tail2 = s;
    }

    node *p, *q;
    node *plus = new node();
    node *tailp = plus;

    p = l1->next;
    q = l2->next;

    while (p && q)
    {
        if (p->val.y == q->val.y)
        {
            if (p->val.x + q->val.x != 0)
            {
                s = new node (p->val.x + q->val.x, p->val.y);
                tailp->next = s;
                tailp = s;
                p = p->next;
                q = q->next;
            }
            else
            {
                p = p->next;
                q = q->next;
            }
        }
        else if(p->val.y > q->val.y)
        {
            s = new node(p->val.x, p->val.y);
            tailp->next = s;
            tailp = s;
            p = p->next;
        }
        else
        {
            s = new node(q->val.x, q->val.y);
            tailp->next = s;
            tailp = s;
            q = q->next;
        }
    }

    while (p)
    {
        s = new node (p->val.x, p->val.y);
        tailp->next = s;
        tailp = s;
        p = p->next;
    }

    while (q)
    {
        s = new node(q->val.x, q->val.y);
        tailp->next = s;
        tailp = s;
        q = q->next;
    }

    node *product = new node();

    p = l1->next;

    while (p)
    {
        q = l2->next;

        while (q)
        {
            item x;

            x.x = p->val.x * q->val.x;
            x.y = p->val.y + q->val.y;
            
            node *qf = product;
            node *f = product->next;

            while (f)
            {
                if (f->val.y <= x.y)
                    break;
                
                qf = f;
                f = f->next;
            }

            if (f)
            {
                if (f->val.y == x.y)
                {
                    if (f->val.x + x.x != 0)
                        f->val.x += x.x;
                    else
                    {
                        qf->next = f->next;
                        delete f;
                    }
                }
                else
                {
                    s = new node(x.x, x.y);
                    s->next = qf->next;
                    qf->next = s;
                }
            }
            else
            {
                s = new node(x.x, x.y);
                s->next = qf->next;
                qf->next = s;
            }

            q = q->next;
        }

        p = p->next;
    }

    p = product->next;

    if (p)
    {
        while (p)
        {
            if (p == product->next)
                cout << p->val.x << " " << p->val.y;
            else
                cout << " " << p->val.x << " " << p->val.y;
            
            p = p->next;
        }
    }
    else
    {
        cout << "0 0";
    }

    cout << endl;

    p = plus->next;

    if (p)
    {
        while (p)
        {
            if (p == plus->next)
                cout << p->val.x << " " << p->val.y;
            else
                cout << " " << p->val.x << " " << p->val.y;

            p = p->next;
        }
    }
    else
    {
        cout << "0 0";
    }

    cout << endl;

    return 0;
}
