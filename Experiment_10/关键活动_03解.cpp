/** 本题其实就是topsort的实现 + 最早/最晚开始时间的计算 */
/** 由于题目不要求输出拓扑序列, 故不需要order数组 */

/** 该解法图的存储为邻接矩阵实现 */

#define vc vector
#define pb push_back

#define INF 0x3f3f3f3f

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
/** TopsortE */
vc<vc<int>> a;
vc<int> ind;
vc<int> elist;
/** TopsortL */
vc<vc<int>> rea;
vc<int> oud;
vc<int> llist;

int topsortE()
{
    int i, j;
    int v;
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
        for (v = 1; v <= n; v++)
        {
            if (a[u][v] != INF)
            {
                int w = a[u][v];
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
    int v;
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
        for (v = 1; v <= n; v++)
        {
            if (rea[u][v] != INF)
            {
                int w = rea[u][v];
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
    int v;
    /** Input */
    cin >> n >> m;
    /** Init a */
    a.assign(n + 1, vc<int>(n + 1, INF));
    /** Init ind */
    ind.assign(n + 1, 0);
    /** Init rea */
    rea.assign(n + 1, vc<int>(n + 1, INF));
    /** Init oud */
    oud.assign(n + 1, 0);

    for (i = 0; i < m; i++)
    {
        int u, v, w;

        cin >> u >> v >> w;

        a[u][v] = w;
        ind[v]++;

        rea[v][u] = w;
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
            for (v = n; v >= 1; v--)
            {
                if (a[i][v] != INF)
                {
                    int w = a[i][v];
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
