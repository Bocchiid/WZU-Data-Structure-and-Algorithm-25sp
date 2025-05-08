/** 本题重点在于bfs + 计算/输出连通分量 */
/** 对于图的部分不做过多的注解 */

/** 本题请严格使用邻接表存储图 */
/** 该解法为邻接表的数组实现 */

/** 本题较坑的点是要对边去重 */
/** 该解法对去重, 使用的是二维数组实现 */

/** 奇数解为全局变量实现 */
/** 偶数解为函数参数实现 */
#define vc vector
#define pb push_back

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vc<char> key;
vc<vc<int>> a;
vc<vc<int>> valid;
vc<bool> visited;

void bfs(int v)
{
    if (visited[v])
        return;

    queue<int> q;
    q.push(v);

    cout << key[v];
    visited[v] = true;

    while (!q.empty())
    {
        int t = q.front();
        q.pop();

        for (int i = a[t].size() - 1; i >= 0; i--)
        {
            int verx = a[t][i];

            if (!visited[verx])
            {
                q.push(verx);

                cout << key[verx];
                visited[verx] = true;
            }
        }
    }
}

int main()
{
    int i, j;
    int kMaxVertex;
    int n, m;
    int u, v, val;
    /** input */
    cin >> kMaxVertex;
    cin >> n >> m;
    /** input vertex */
    key.resize(n);

    for (i = 0; i < n; i++)
        cin >> key[i];
    /** input edge */
    a.resize(n);
    valid.assign(n, vc<int>(n, 0)); // valid.resize(n, vc<int>(n, 0));

    for (i = 0; i < m; i++)
    {
        cin >> u >> v >> val;

        if (!valid[u][v] && !valid[v][u])
        {
            a[u].pb(v);
            a[v].pb(u);
            valid[u][v] = 1;
            valid[v][u] = 1;
        }
    }
    /** bfs */
    visited.assign(n, false); // visited.resize(n, false);

    for (i = 0; i < n; i++)
        if (!visited[i])
        {
            bfs(i);
            cout << endl;
        }

    return 0;
}
