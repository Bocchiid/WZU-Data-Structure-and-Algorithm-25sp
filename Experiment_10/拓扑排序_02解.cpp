/** 该解法图的存储为邻接表实现 */
/** 该解法的邻接表为链表实现 */

#define vc vector
#define pb push_back

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge
{
    int v;
    edge *next;

    edge() : v(0), next(nullptr) {}
    edge(int v) : v(v), next(nullptr) {}
};

int n, m;

vc<string> key;
vc<edge *> a;
vc<int> ind;
vc<int> order;

bool topsort()
{
    int i, j;
    /** init order */
    order.assign(n, 0);
    /** make counting */
    int cnt = 0;
    /** make a queue */
    queue<int> q;
    /** push items which ind equals zero */
    for (i = 0; i < n; i++)
        if (!ind[i])
            q.push(i);

    while (!q.empty())
    { /** pop item from queue */
        int u = q.front();
        q.pop();
        /** add order */
        order[cnt] = u;
        /** counting++ */
        cnt++;
        /** reduce ind */
        edge *p = a[u]->next;

        while (p)
        {
            int v = p->v;
            ind[v]--;
            /** push items which ind equals zero */
            if (!ind[v])
                q.push(v);

            p = p->next;
        }
    }

    if (cnt == n)
        return true;

    return false;
}

int main()
{
    int i, j, k;
    /** input */
    cin >> n >> m;
    /** input vertex */
    key.resize(n);

    for (i = 0; i < n; i++)
        cin >> key[i];
    /** input edge */
    /** init a array */
    a.resize(n);

    for (i = 0; i < n; i++)
        a[i] = new edge();
    /** init ind array */
    ind.assign(n, 0);

    for (i = 0; i < m; i++)
    {
        int u, v;

        cin >> u >> v;
        edge *ed = new edge(v);

        ed->next = a[u]->next;
        a[u]->next = ed;

        ind[v]++;
    }
    /** topsort */
    bool flag = topsort();

    cout << "该图拓扑序存在性为 " << flag << endl;
    /** output order */
    for (i = 0; i < n; i++)
        cout << key[order[i]] << " ";

    cout << endl;

    return 0;
}
