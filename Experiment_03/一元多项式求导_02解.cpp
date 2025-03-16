/* 题目描述中的零多项式指的是最后的答案多项式为0, 然后输出0 0 */
/* 该题为PAT乙级原题 */
/* 该解法为与实验目的相匹配的链表解法 */

#include <iostream>
using namespace std;

struct Data
{
    int a;
    int b;
};

struct node
{
    Data val;
    struct node* next;

    node()
    {
        val.a = 0;
        val.b = 0;
        next = nullptr; // next = NULL;
    }

    node(Data x)
    {
        val.a = x.a;
        val.b = x.b;
        next = nullptr; // next = NULL;
    }
};

int main()
{
    Data x;
    node *dummy = new node();
    node *s;
    node *tail = dummy;

    while (cin >> x.a >> x.b)
    {
        if (x.b != 0) //常数c求导后的结果为0
        {
            x.a *= x.b;
            x.b -= 1;
            s = new node(x);
            tail->next =s;
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
                cout << " ";

            cout << p->val.a << " " << p->val.b;
            p = p->next;
        }
    }
    else
        cout << "0 0";

    cout << endl;

    return 0;
}
