/** 本题重点在于dfs + 计算/输出连通分量 */
/** 对于图的部分不做过多的注解 */

/** 本题请严格使用邻接表存储图 */
/** 该解法为邻接表的链表实现 */

/** 本题较坑的点是要对边去重 */
/** 该解法对去重, 使用的是暴力搜索实现 */

/** 奇数解为全局变量实现 */
/** 偶数解为函数参数实现 */
#define vc vector

#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int v;
    node *next;

    node() : v(0), next(nullptr) {}
    node(int v) : v(v), next(nullptr) {}
};

bool find(vc<node *> &a, int u, int v)
{
    node *p = a[u]->next;

    while (p)
    {
        if (p->v == v)
            return true;

        p = p->next;
    }

    p = a[v]->next;

    while (p)
    {
        if (p->v == u)
            return true;

        p = p->next;
    }

    return false;
}

void dfs(int v, vc<node *> &a, vc<char> &key, vc<bool> &visited)
{
    if (visited[v])
        return;

    cout << key[v];
    visited[v] = true;

    node *p = a[v]->next;

    while (p)
    {
        dfs(p->v, a, key, visited);
        p = p->next;
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
    vc<vc<int>> valid(n, vc<int>(n, 0));

    for (i = 0; i < n; i++)
        a[i] = new node();

    for (i = 0; i < m; i++)
    {
        cin >> u >> v >> val;

        if (!find(a, u, v))
        {
            node *s = new node(v);
            s->next = a[u]->next;
            a[u]->next = s;

            s = new node(u);
            s->next = a[v]->next;
            a[v]->next = s;
        }
    }
    /** dfs */
    vc<bool> visited(n, false);

    for (i = 0; i < n; i++)
        if (!visited[i])
        {
            dfs(i, a, key, visited);
            cout << endl;
        }

    return 0;
}
