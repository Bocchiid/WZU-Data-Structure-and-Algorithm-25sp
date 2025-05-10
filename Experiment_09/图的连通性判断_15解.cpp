/** 本题重点在于bfs + 计算/输出连通分量 */
/** 对于图的部分不做过多的注解 */

/** 本题请严格使用邻接表存储图 */
/** 该解法为邻接表的链表实现 */

/** 本题较坑的点是要对边去重 */
/** 该解法对去重, 使用的是暴力搜索实现 */

/** 奇数解为全局变量实现 */
/** 偶数解为函数参数实现 */

/** 本题其实就是在7-4的基础上增加了计算连通分量数 */
/** 所以代码相似度极高 */
/** 外部的一次访问就是一个连通分量 */
#define vc vector

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int v;
    node *next;

    node() : v(0), next(nullptr) {}
    node(int v) : v(v), next(nullptr) {}
};

vc<char> key;
vc<node *> a;
vc<bool> visited;

bool find(int u, int v)
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

void bfs(int v)
{
    if (visited[v])
        return;

    queue<int> q;
    q.push(v);

    cout << key[v];
    visited[v] = true;

    while (!q.empty())
    {
        int t = q.front();
        q.pop();

        node *p = a[t]->next;

        while (p)
        {
            int vert = p->v;

            if (!visited[vert])
            {
                q.push(vert);

                cout << key[vert];
                visited[vert] = true;
            }

            p = p->next;
        }
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
    key.resize(n);

    for (i = 0; i < n; i++)
        cin >> key[i];
    /** input edge */
    a.resize(n);

    for (i = 0; i < n; i++)
        a[i] = new node();

    for (i = 0; i < m; i++)
    {
        cin >> u >> v >> val;

        if (!find(u, v))
        {
            node *s = new node(v);
            s->next = a[u]->next;
            a[u]->next = s;

            s = new node(u);
            s->next = a[v]->next;
            a[v]->next = s;
        }
    }
    /** bfs */
    int cnt = 0;

    visited.assign(n, false); // visited.resize(n, false);

    for (i = 0; i < n; i++)
        if (!visited[i])
        {
            cnt++;
            bfs(i);
            cout << endl;
        }

    if (cnt != 1)
        cout << "有 " << cnt << " 个连通分量" << endl;

    cout << "该图连通性为 ";

    if (cnt == 1)
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}
