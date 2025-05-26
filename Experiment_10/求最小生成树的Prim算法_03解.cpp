/** prim其实就是特殊的dijkstra */

/** 该解法图的存储为邻接表实现 */
/** 该解法的邻接表为链表实现 */
/** 该解法的prim为堆优化实现 */

#define vc vector
#define pb push_back

#define INF 0x3f3f3f3f

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge
{
    int v;
    int w;
    edge *next;

    edge() : v(0), w(0), next(nullptr) {}
    edge(int v, int w) : v(v), w(w), next(nullptr) {}
};

struct cmp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        if (a.first > b.first)
            return true;
        else if (a.first == b.first && a.second > b.second)
            return true;

        return false;
    }
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
    /** Make heap */
    priority_queue<pair<int, int>, vc<pair<int, int>>, cmp> pq;
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
        /** Push vertex whose min cost was updated */
        pq.push({cost[v], v});

        p = p->next;
    }
    /** Make counting */
    int cnt = 0;
    /** Make weight */
    int weight = 0;
    /** Visit vertex s */
    weight += cost[s];
    cost[s] = 0;
    cnt++;
    parent[s] = -1;

    while (!pq.empty())
    { /** Get min cost vertex u */
        int u = pq.top().second;
        pq.pop();
        /** If in tree(cost == 0), continue */
        if (!cost[u])
            continue;
        /** Or, visit vertex u */
        weight += cost[u];
        cost[u] = 0;
        cnt++; /** Counting++ */
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
                /** Push vertex whose min cost was updated */
                pq.push({cost[v], v});
            }

            p = p->next;
        }
    }

    if (cnt == n)
        return weight;

    return -1;
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
