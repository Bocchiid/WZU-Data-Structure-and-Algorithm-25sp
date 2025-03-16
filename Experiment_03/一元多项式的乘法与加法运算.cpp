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
        next = nullptr; // next = NULL;
    }

    node(item that)
    {
        val.x = that.x;
        val.y = that.y;
        next = nullptr;
    }
};

int main()
{
    item x;
    node *l1 = new node();
    node *l2 = new node();
    node *s;
    node *t1 = l1;
    node *t2 = l2;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x.x >> x.y;
        s = new node(x);
        t1->next = s;
        t1 = s;
    }

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x.x >> x.y;
        s = new node(x);
        t2->next = s;
        t2 = s;
    }

    node *p, *q;
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
                    int num;

                    num = f->val.x + x.x;

                    if (num)
                        f->val.x += x.x;
                    else
                    {
                        qf->next = f->next;
                        delete f; // 这句话可以不要
                    }
                }
                else
                {
                    s = new node(x);
                    s->next = qf->next;
                    qf->next = s;
                }
            }
            else
            {
                s = new node(x);
                qf->next = s;
                qf = s;
            }
            
            q = q->next;
        }
        
        p = p->next;
    }

    node *plus = new node();
    node *tp = plus;

    p = l1->next;
    q = l2->next;

    while (p && q)
    {
        if (p->val.y == q->val.y)
        {
            int sum = p->val.x + q->val.x;

            if (sum)
            {
                item x;

                x.x = sum;
                x.y = p->val.y; // x.y = q->val.y;
                s = new node(x);
                tp->next = s;
                tp = s;
            }

            p = p->next;
            q = q->next;
        }
        else if (p->val.y > q->val.y)
        {
            s = new node(p->val);
            tp->next = s;
            tp = s;
            p = p->next;
        }
        else
        {
            s = new node(q->val);
            tp->next = s;
            tp = s;
            q = q->next;
        }
    }

    while (p)
    {
        s = new node(p->val);
        tp->next = s;
        tp = s;
        p = p->next;
    }

    while (q)
    {
        s = new node(q->val);
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
                cout << " ";
    
            cout << p->val.x << " " << p->val.y;
            p = p->next;
        }
    }
    else
        cout << "0 0";

    cout << endl;
    p = plus->next;

    if (plus->next) // if (p)也行
    {
        while (p)
        {
            if (p != plus->next)
                cout << " ";
    
            cout << p->val.x << " " << p->val.y;
            p = p->next;
        }
    }
    else
        cout << "0 0";

    cout << endl;

    return 0;
}
