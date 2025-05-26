/** prim其实就是特殊的dijkstra */

/** 该解法图的存储为邻接表实现 */
/** 该解法的邻接表为链表实现 */
/** 该解法的prim为BF实现 */

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
vc<int> cost;
vc<int> parent;

int prim(int s)
{
    int i, j;
    /** Init parent */
    parent.assign(n, 0);
    /** Init cost */
    cost.assign(n, INF);
    cost[s] = 0;

    edge *p = a[s]->next;

    while (p)
    {
        int v = p->v;
        int w = p->w;
        /** Actually, cost[s] == 0 */
        cost[v] = w; /** cost[v] = cost[s] + w */
        parent[v] = s;

        p = p->next;
    }
    /** Make weight */
    int weight = 0;
    /** Visit vertex s */
    weight += cost[s];
    cost[s] = 0;
    parent[s] = -1;

    for (i = 1; i < n; i++)
    {
        int u, mind;

        u = -1;
        mind = INF;
        /** Find min cost vertex u */
        for (j = 0; j < n; j++)
            if (cost[j] && cost[j] < mind)
            {
                mind = cost[j];
                u = j;
            }
        /** If exists */
        if (u != -1)
        { /** Visit vertex u */
            weight += cost[u];
            cost[u] = 0;
            /** Try to update min cost */
            edge *p = a[u]->next;

            while (p)
            {
                int v = p->v;
                int w = p->w;
                /** Actually, cost[u] == 0 */
                if (w < cost[v]) /** cost[u] + w < cost[v] */
                {
                    cost[v] = w; /** cost[v] = cost[u] + w */
                    parent[v] = u;
                }

                p = p->next;
            }
        }
        else /** Or, return -1 */
            return -1;
    }

    return weight;
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

        ed = new edge(u, w);
        ed->next = a[v]->next;
        a[v]->next = ed;
    }
    /** Do prim */
    int weight = prim(0);
    /** Output */
    cout << "total weight = " << weight << endl;
    /** Output parent */
    for (i = 0; i < n; i++)
        cout << parent[i] << " ";

    return 0;
}
