/** 该解法图的存储为邻接矩阵实现 */

#define vc vector
#define pb push_back

#define INF 0x3f3f3f3f

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;

vc<string> key;
vc<vc<int>> a;
vc<int> ind;
vc<int> order;

bool topsort()
{
    int i, j;
    int v;
    /** Init order */
    order.assign(n, 0);
    /** Make counting */
    int cnt = 0;
    /** Make a queue */
    queue<int> q;
    /** Push vertex whose ind equals zero */
    for (i = 0; i < n; i++)
        if (!ind[i])
            q.push(i);

    while (!q.empty())
    { /** Get vertex whose ind equals zero */
        int u = q.front();
        q.pop();
        /** Add order */
        order[cnt] = u;
        /** Counting++ */
        cnt++;
        /** Reduce ind */
        for (v = 0; v < n; v++)
        {
            if (a[u][v] != INF)
            {
                ind[v]--;
                /** Push vertex whose ind equals zero */
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
    int i, j;
    /** Input */
    cin >> n >> m;
    /** Input vertex */
    /** Init key */
    key.resize(n);

    for (i = 0; i < n; i++)
        cin >> key[i];
    /** Input edge */
    /** Init a */
    a.assign(n, vc<int>(n, INF));
    /** Init ind */
    ind.assign(n, 0);

    for (i = 0; i < m; i++)
    {
        int u, v;

        cin >> u >> v;
        a[u][v] = 0;
        ind[v]++;
    }
    /** Do topsort */
    bool flag = topsort();
    /** Output */
    cout << "该图拓扑序存在性为 " << flag << endl;
    /** Output order */
    for (i = 0; i < n; i++)
        cout << key[order[i]] << " ";

    cout << endl;

    return 0;
}
