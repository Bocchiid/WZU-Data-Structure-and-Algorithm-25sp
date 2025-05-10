/** 03和04解的区别在于是否是函数式实现 */
/** 03解为非函数式(大部分)实现 */
/** 03和04解为邻接表的链表实现 */

#define vc vector

#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int v;
    int w;
    node *next;

    node() : v(0), w(0), next(nullptr) {}
    node(int v, int w) : v(v), w(w), next(nullptr) {}
};
/** 输出邻接表 */
void print(vc<node *> &a, int size)
{
    int i;
    node *p;

    cout << "邻接表为：" << endl;

    for (i = 0; i < size; i++)
    {
        cout << "list[" << i << "]";
        p = a[i]->next;

        while (p)
        {
            cout << "->" << p->v << ":" << p->w;
            p = p->next;
        }

        cout << "->end" << endl;
    }
}

int main()
{
    int i, j;
    int kMaxVertex;
    int n, m;
    int u, v, val;
    /** input */
    cin >> kMaxVertex;
    cin >> n >> m;
    /** input vertex */
    vc<char> key(n);

    for (i = 0; i < n; i++)
        cin >> key[i];
    /** input edge */
    vc<node *> a(n);

    for (i = 0; i < n; i++)
        a[i] = new node();

    for (i = 0; i < m; i++)
    {
        cin >> u >> v >> val;
        /** 头插法构建链表 */
        node *s = new node(v, val);
        s->next = a[u]->next;
        a[u]->next = s;
        /** 根据题目的意思, 本题不会出现重复输入的边, 但题目表述未提及，不严谨 */
    }

    print(a, n);                      /** 输出邻接表 */
    cout << "顶点数 = " << n << endl; /** 输出结点数 */
    /** 判断边的存在性 */
    for (i = 0; i < 2; i++)
    {
        cin >> u >> v;
        cout << "<" << u << ", " << v << "> 的存在性 = ";

        node *p = a[u]->next;
        bool found = false;

        while (p)
        {
            if (p->v == v)
            {
                found = true;
                break;
            }

            p = p->next;
        }

        if (found)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    /** 寻找点的第一个邻接点 */
    cin >> u; /** 按题目的意思保证一定有, 所以直接输出, 但其实不严谨 */
    cout << "顶点" << u << "的第一个邻接点 = " << a[u]->next->v << endl;
    /** 删除一个结点 */
    cin >> u;
    cout << "待删除的顶点信息为 " << key[u] << endl;
    key[u] = key[n - 1]; /** 覆盖结点 */
    /** 覆盖待删除的结点 */
    a[u] = a[n - 1];
    /** 结点数-1 */
    n--;
    /** 删除拥有待删除的结点的边 */
    for (i = 0; i < n; i++)
    {
        node *q = a[i];
        node *p = a[i]->next;

        while (p)
        {
            if (p->v == u)
                q->next = p->next;
            else
                q = p;

            p = p->next;
        }
    }
    /** 修改相应邻接点 */
    for (i = 0; i < n; i++)
    {
        node *p = a[i]->next;

        while (p)
        {
            if (p->v == n)
                p->v = u;

            p = p->next;
        }
    }
    /** 输出结点数 */
    cout << "当前顶点数 = " << n << endl;
    /** 输出边数 */
    int cnt = 0;

    for (i = 0; i < n; i++)
    {
        node *p = a[i]->next;

        while (p)
        {
            cnt++;
            p = p->next;
        }
    }

    cout << "当前边数 = " << cnt << endl;
    /** 输出结点 */
    for (i = 0; i < n; i++)
        cout << key[i];

    cout << endl;
    /** 输出邻接表 */
    print(a, n);

    return 0;
}
