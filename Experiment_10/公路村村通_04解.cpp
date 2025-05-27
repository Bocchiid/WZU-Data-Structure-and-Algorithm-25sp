/** 本题其实就是7-3prim算法的实现 */
/** 由于题目不要求输出树的序列, 故不需要parent数组 */

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

int prim(int s)
{
    int i, j;
    /** Init cost */
    cost.assign(n + 1, INF);
    cost[s] = 0;

    edge *p = a[s]->next;

    while (p)
    {
        int v = p->v;
        int w = p->w;
        /** Actually, cost[s] == 0 */
        cost[v] = w; /** cost[v] = cost[s] + w */

        p = p->next;
    }
    /** Make weight */
    int weight = 0;
    /** Visit vertex s */
    weight += cost[s];
    cost[s] = 0;

    for (i = 1; i < n; i++)
    {
        int u, mind;

        u = -1;
        mind = INF;
        /** Find min cost vertex u */
        for (j = 1; j <= n; j++)
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
    a.resize(n + 1);

    for (i = 1; i <= n; i++)
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
    int weight = prim(1);
    /** Output */
    cout << weight << endl;

    return 0;
}
