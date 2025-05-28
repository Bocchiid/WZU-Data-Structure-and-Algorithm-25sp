/** 本题其实就是topsort的实现 + 最早完成时间的计算 */
/** 由于题目不要求输出拓扑序列, 故不需要order数组 */

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
    int w;
    edge *next;

    edge() : v(0), w(0), next(nullptr) {}
    edge(int v, int w) : v(v), w(w), next(nullptr) {}
};

int n, m;

vc<edge *> a;
vc<int> ind;
vc<int> elist;

int topsort()
{
    int i, j;
    /** Init elist */
    elist.assign(n, 0);
    /** Make counting */
    int cnt = 0;
    /** Make maxtime */
    int maxtime = 0;
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
        /** Counting++ */
        cnt++;
        /** Try to update maxtime */
        maxtime = max(maxtime, elist[u]);
        /** Reduce ind */
        edge *p = a[u]->next;

        while (p)
        {
            int v = p->v;
            int w = p->w;
            /** Try to update elist */
            elist[v] = max(elist[v], elist[u] + w);
            ind[v]--;
            /** Push vertex whose ind equals zero */
            if (!ind[v])
                q.push(v);

            p = p->next;
        }
    }

    if (cnt == n)
        return maxtime;

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
    /** Init ind */
    ind.assign(n, 0);

    for (i = 0; i < m; i++)
    {
        int u, v, w;

        cin >> u >> v >> w;

        edge *ed = new edge(v, w);
        ed->next = a[u]->next;
        a[u]->next = ed;
        ind[v]++;
    }
    /** Do topsort */
    int maxtime = topsort();
    /** Output */
    if (maxtime != -1)
        cout << maxtime << endl;
    else
        cout << "Impossible" << endl;

    return 0;
}
