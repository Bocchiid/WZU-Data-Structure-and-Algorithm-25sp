邻接表表示的图基本操作/** 03和04解的区别在于是否是函数式实现 */
/** 04解为函数式实现 */
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
/** 输出结点 */
void printVertex(vc<char> &key, int size)
{
    int i;

    for (i = 0; i < size; i++)
        cout << key[i];

    cout << endl;
}
/** 插入边 */
void insertEdge(vc<node *> &a, int u, int v, int val)
{ /** 头插法构建链表 */
    node *s = new node(v, val);
    s->next = a[u]->next;
    a[u]->next = s;
}
/** 判断边的存在性 */
bool edgeValid(vc<node *> &a, int u, int v)
{
    node *p = a[u]->next;

    while (p)
    {
        if (p->v == v)
            return true;

        p = p->next;
    }

    return false;
}
/** 获取邻接点 */
int getAdjnode(vc<node *> &a, int v)
{ /** 按题目的意思保证一定有, 所以直接输出, 但其实不严谨 */
    return a[v]->next->v;
}
/** 删除结点 */
void deleteVertex(vc<node *> &a, vc<char> &key, int v, int &size)
{
    int i;

    cout << "待删除的顶点信息为 " << key[v] << endl;
    key[v] = key[size - 1]; /** 覆盖结点 */
    /** 覆盖待删除的结点 */
    a[v] = a[size - 1];
    /** 结点数-1 */
    size--;
    /** 删除拥有待删除的结点的边 */
    for (i = 0; i < size; i++)
    {
        node *q = a[i];
        node *p = a[i]->next;

        while (p)
        {
            if (p->v == v)
                q->next = p->next;
            else
                q = p;

            p = p->next;
        }
    }
    /** 修改相应邻接点 */
    for (i = 0; i < size; i++)
    {
        node *p = a[i]->next;

        while (p)
        {
            if (p->v == size)
                p->v = v;

            p = p->next;
        }
    }
}
/** 获取结点数 */
int countVertex(int n)
{
    return n;
}
/** 获取边数 */
int countEdge(vc<node *> &a, int size)
{
    int i;
    int cnt = 0;

    for (i = 0; i < size; i++)
    {
        node *p = a[i]->next;

        while (p)
        {
            cnt++;
            p = p->next;
        }
    }

    return cnt;
}
/** 输出结点数 */
void printCountVertex(int n)
{
    cout << "顶点数 = " << countVertex(n) << endl;
}
/** 输出边的存在性 */
void printEdgeValid(vc<node *> &a, int u, int v)
{
    cout << "<" << u << ", " << v << "> 的存在性 = " << edgeValid(a, u, v) << endl;
}
/** 输出边数 */
void printCountEdge(vc<node *> &a, int size)
{
    cout << "边数 = " << countEdge(a, size) << endl;
}
/** 输出邻接点 */
void printAdjnode(vc<node *> &a, int v)
{
    cout << "顶点" << v << "的第一个邻接点 = " << getAdjnode(a, v) << endl;
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
        insertEdge(a, u, v, val);
        /** 根据题目的意思, 本题不会出现重复输入的边, 但题目表述未提及，不严谨 */
    }

    print(a, n);         /** 输出邻接表 */
    printCountVertex(n); /** 输出结点数 */
    /** 判断边的存在性 */
    for (i = 0; i < 2; i++)
    {
        cin >> u >> v;
        printEdgeValid(a, u, v);
    }
    /** 寻找点的第一个邻接点 */
    cin >> u;
    printAdjnode(a, u);
    /** 删除一个结点 */
    cin >> u;
    deleteVertex(a, key, u, n);
    /** 输出结点数 */
    cout << "当前";
    printCountVertex(n);
    /** 输出边数 */
    cout << "当前";
    printCountEdge(a, n);
    /** 输出结点 */
    printVertex(key, n);
    /** 输出邻接表 */
    print(a, n);

    return 0;
}
