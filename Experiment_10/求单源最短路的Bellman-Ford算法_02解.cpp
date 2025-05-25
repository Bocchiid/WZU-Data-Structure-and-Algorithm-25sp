/** 该解法图的存储为邻接表实现 */
/** 该解法的邻接表为链表实现 */

#define vc vector
#define pb push_back

#define INF 0x3f3f3f3f

#include <iostream>
#include <vector>
using namespace std;

struct edge
{
    int v;
    int w;
    edge *next;

    edge() : v(0), w(0), next(nullptr) {}
    edge(int v, int w) : v(v), w(w), next(nullptr) {}
};

int n, m;

vc<edge *> a;
vc<int> dist;
vc<int> path;

bool bellman_ford(int s)
{
    int i, j;
    /** Init dist */
    dist.assign(n, INF);
    /** Init path */
    path.assign(n, -1);
    /** Visit vertex s */
    dist[s] = 0;
    path[s] = -1;
    /** Visit other vertexes */
    for (i = 1; i < n; i++)
    { /** Visit evert edge */
        for (j = 0; j < n; j++)
        {
            edge *p = a[j]->next;

            while (p)
            {
                int u = j;
                int v = p->v;
                int w = p->w;
                /** Try to update shortest dist */
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    path[v] = u;
                }

                p = p->next;
            }
        }
    }
    /** Check negative circle */
    for (j = 0; j < n; j++)
    {
        edge *p = a[j]->next;

        while (p)
        {
            int u = j;
            int v = p->v;
            int w = p->w;

            if (dist[u] + w < dist[v])
                return false;

            p = p->next;
        }
    }

    return true;
}

int main()
{
    int i, j;
    /** Input */
    cin >> n >> m;
    /** Input edge */
    /** Init a */
    a.resize(n);

    for (i = 0; i < n; i++)
        a[i] = new edge();

    for (i = 0; i < m; i++)
    {
        int u, v, w;

        cin >> u >> v >> w;
        edge *ed = new edge(v, w);

        ed->next = a[u]->next;
        a[u]->next = ed;
    }
    /** Do bellman_ford */
    bool flag = bellman_ford(0);
    /** Output */
    cout << "BF returns " << flag << endl;
    /** Output dist */
    for (i = 0; i < n; i++)
        cout << "dist[" << i << "] = " << dist[i] << endl;

    return 0;
}
