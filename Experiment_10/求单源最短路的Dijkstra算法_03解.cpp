/** 该解法图的存储为邻接表实现 */
/** 该解法的邻接表为链表实现 */
/** 该解法的dijkstra为堆优化实现 */

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
vc<int> dist;
vc<int> path;
vc<bool> visited;

void dijkstra(int s)
{
    int i, j;

    dist.assign(n, INF);
    path.assign(n, -1);
    visited.assign(n, false);

    dist[s] = 0;
    path[s] = -1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({dist[s], s});

    while (!pq.empty())
    { /** 通过堆, 获取最小距离结点 */
        int u = pq.top().second;
        pq.pop();
        /** 若结点被访问过了, 则继续寻找 */
        if (visited[u])
            continue;
        /** 否则, 访问结点 */
        visited[u] = true;
        /** 尝试更新邻接点的最小距离 */
        edge *p = a[u]->next;

        while (p)
        {
            int v = p->v;
            int w = p->w;
            /** 若经过u到达v的权比之前到达v的权更新, 则更新 */
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                path[v] = u;
                /** 将最小距离被更新的结点推入堆中 */
                pq.push({dist[v], v});
            }

            p = p->next;
        }
    }
}

int main()
{
    int i, j, k;
    /** input */
    cin >> n >> m;
    /** input edge */
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
    /** dijkstra */
    dijkstra(0);
    /** output path */
    for (i = 0; i < n; i++)
        cout << "v[" << i << "]: dist=" << dist[i] << ", path=" << path[i] << endl;

    return 0;
}
