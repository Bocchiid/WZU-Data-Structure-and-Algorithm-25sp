/** 本题其实就是topsort的实现 + 最早/最晚开始时间的计算 */
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
/** TopsortE */
vc<edge *> a;
vc<int> ind;
vc<int> elist;
/** TopsortL */
vc<edge *> rea;
vc<int> oud;
vc<int> llist;

int topsortE()
{
    int i, j;
    /** Init elist */
    elist.assign(n + 1, 0);
    /** Make counting */
    int cnt = 0;
    /** Make maxtime */
    int maxtime = 0;
    /** Make a queue */
    queue<int> q;
    /** Push vertex whose ind equals zero */
    for (i = 1; i <= n; i++)
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

int topsortL(int maxtime)
{
    int i, j;
    /** Init llist */
    llist.assign(n + 1, maxtime);
    /** Make counting */
    int cnt = 0;
    /** Make mintime */
    int mintime = maxtime;
    /** Make a queue */
    queue<int> q;
    /** Push vertex whose oud equals zero */
    for (i = 1; i <= n; i++)
        if (!oud[i])
            q.push(i);

    while (!q.empty())
    { /** Get vertex whose oud equals zero */
        int u = q.front();
        q.pop();
        /** Counting++ */
        cnt++;
        /** Try to update mintime */
        mintime = min(mintime, llist[u]);
        /** Reduce oud */
        edge *p = rea[u]->next;

        while (p)
        {
            int v = p->v;
            int w = p->w;
            /** Try to update llist */
            llist[v] = min(llist[v], llist[u] - w);
            oud[v]--;
            /** Push vertex whose oud equals zero */
            if (!oud[v])
                q.push(v);

            p = p->next;
        }
    }

    if (cnt == n)
        return mintime;

    return -1;
}

int main()
{
    int i, j;
    /** Input */
    cin >> n >> m;
    /** Init a */
    a.resize(n + 1);

    for (i = 1; i <= n; i++)
        a[i] = new edge();
    /** Init ind */
    ind.assign(n + 1, 0);
    /** Init rea */
    rea.resize(n + 1);

    for (i = 1; i <= n; i++)
        rea[i] = new edge();
    /** Init oud */
    oud.assign(n + 1, 0);

    for (i = 0; i < m; i++)
    {
        int u, v, w;

        cin >> u >> v >> w;

        edge *ed = new edge(v, w);
        ed->next = a[u]->next;
        a[u]->next = ed;
        ind[v]++;

        ed = new edge(u, w);
        ed->next = rea[v]->next;
        rea[v]->next = ed;
        oud[u]++;
    }
    /** Do topsortE */
    int maxtime = topsortE();
    /** Check topsortE */
    if (maxtime != -1)
    { /** Do topsortL */
        topsortL(maxtime);
        /** Output */
        cout << maxtime << endl;
        /** Output critical activities */
        for (i = 1; i <= n; i++)
        {
            edge *p = a[i]->next;

            while (p)
            {
                int v = p->v;
                int w = p->w;
                /** Check critical activity */
                if (llist[v] - w == elist[i])
                    cout << i << "->" << v << endl;

                p = p->next;
            }
        }
    }
    else
        cout << 0 << endl;

    return 0;
}
