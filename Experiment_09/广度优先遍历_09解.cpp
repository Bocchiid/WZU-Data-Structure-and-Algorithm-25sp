/** 本题重点在于bfs + 计算/输出连通分量 */
/** 对于图的部分不做过多的注解 */

/** 本题请严格使用邻接表存储图 */
/** 该解法为邻接表的链表实现 */

/** 本题较坑的点是要对边去重 */
/** 该解法对去重, 使用的是set实现 */

/** 奇数解为全局变量实现 */
/** 偶数解为函数参数实现 */
#define vc vector
#define pb push_back

#include <iostream>
#include <vector>
#include <set>
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
set<pair<int, int>> st;
vc<bool> visited;

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

        if (!st.count({u, v}) && !st.count({v, u}))
        {
            node *s = new node(v);
            s->next = a[u]->next;
            a[u]->next = s;

            s = new node(u);
            s->next = a[v]->next;
            a[v]->next = s;

            st.insert({u, v});
            st.insert({v, u});
        }
    }
    /** bfs */
    visited.assign(n, false);

    for (i = 0; i < n; i++)
        if (!visited[i])
        {
            bfs(i);
            cout << endl;
        }

    return 0;
}
