/** 该解法图的存储为直接存储边实现 */

#define vc vector
#define pb push_back

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge
{
    int u;
    int v;
};

int n, m;

vc<string> key;
vc<edge> a;
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
    /** push items whose ind equals zero */
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
        for (i = 0; i < m; i++)
        { /** find edge with beginning point u */
            if (a[i].u == u)
            {
                int v = a[i].v;

                ind[v]--;
                /** push items whose ind equals zero */
                if (!ind[v])
                    q.push(v);
            }
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
    a.resize(m);
    /** init ind array */
    ind.assign(n, 0);

    for (i = 0; i < m; i++)
    {
        int u, v;

        cin >> u >> v;
        a[i] = {u, v};

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
