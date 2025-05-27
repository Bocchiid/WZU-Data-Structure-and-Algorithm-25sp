/** 本题其实就是7-3prim算法的实现 */

/** 该解法图的存储为邻接矩阵实现 */
/** 该解法的prim为堆优化实现 */

#define vc vector
#define pb push_back

#define INF 0x3f3f3f3f

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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

vc<vc<int>> a;
vc<int> cost;
vc<int> parent;

int prim(int s)
{
    int i, j;
    int v;
    /** Init parent */
    parent.assign(n + 1, 1);
    /** Make heap */
    priority_queue<pair<int, int>, vc<pair<int, int>>, cmp> pq;
    /** Init cost */
    cost.assign(n + 1, INF);
    cost[s] = 0;

    for (v = 1; v <= n; v++)
    {
        if (a[s][v] != INF)
        {
            int w = a[s][v];
            /** Actually, cost[s] == 0 */
            cost[v] = w; /** cost[v] = cost[s] + w */
            /** Push vertex whose min cost was updated */
            pq.push({cost[v], v});
        }
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
        for (v = 1; v <= n; v++)
        {
            if (a[u][v] != INF)
            {
                int w = a[u][v];
                /** Actually, cost[u] == 0 */
                if (w < cost[v]) /** cost[u] + w < cost[v] */
                {
                    cost[v] = w; /** cost[v] = cost[u] + w */
                    parent[v] = u;
                    /** Push vertex whose min cost was updated */
                    pq.push({cost[v], v});
                }
            }
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
    a.assign(n + 1, vc<int>(n + 1, INF));

    for (i = 0; i < m; i++)
    {
        int u, v, w;

        cin >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
    }
    /** Do prim */
    int weight = prim(1);
    /** Output */
    cout << weight << endl;

    return 0;
}
