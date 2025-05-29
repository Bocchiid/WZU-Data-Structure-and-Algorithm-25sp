/** 本题其实就是topsort的实现 + 最早/最晚开始时间的计算 */
/** 由于题目不要求输出拓扑序列, 故不需要order数组 */

/** 该解法图的存储为直接存储边实现 */

#define vc vector
#define pb push_back

#define INF 0x3f3f3f3f

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge
{
    int u;
    int v;
    int w;
};

int n, m;
/** TopsortE */
vc<edge> a;
vc<int> ind;
vc<int> elist;
/** TopsortL */
vc<edge> rea;
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
        for (i = 0; i < m; i++)
        {
            if (a[i].u == u)
            {
                int v = a[i].v;
                int w = a[i].w;
                /** Try to update elist */
                elist[v] = max(elist[v], elist[u] + w);
                ind[v]--;
                /** Push vertex whose ind equals zero */
                if (!ind[v])
                    q.push(v);
            }
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
        for (i = 0; i < m; i++)
        {
            if (rea[i].u == u)
            {
                int v = rea[i].v;
                int w = rea[i].w;
                /** Try to update llist */
                llist[v] = min(llist[v], llist[u] - w);
                oud[v]--;
                /** Push vertex whose oud equals zero */
                if (!oud[v])
                    q.push(v);
            }
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
    /** Init ind */
    ind.assign(n + 1, 0);
    /** Init oud */
    oud.assign(n + 1, 0);

    for (i = 0; i < m; i++)
    {
        int u, v, w;

        cin >> u >> v >> w;

        a.pb({u, v, w});
        ind[v]++;

        rea.pb({v, u, w});
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
            for (j = m - 1; j >= 0; j--)
            {
                if (a[j].u == i)
                {
                    int v = a[j].v;
                    int w = a[j].w;
                    /** Check critical activity */
                    if (llist[v] - w == elist[i])
                        cout << i << "->" << v << endl;
                }
            }
        }
    }
    else
        cout << 0 << endl;

    return 0;
}
