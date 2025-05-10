/** 本题重点在于dfs + 计算/输出连通分量 */
/** 对于图的部分不做过多的注解 */

/** 本题请严格使用邻接表存储图 */
/** 该解法为邻接表的数组实现 */

/** 本题较坑的点是要对边去重 */
/** 该解法对去重, 使用的是暴力搜索实现 */

/** 奇数解为全局变量实现 */
/** 偶数解为函数参数实现 */
#define vc vector
#define pb push_back

#include <iostream>
#include <vector>
using namespace std;

bool find(vc<vc<int>> &a, int u, int v)
{
    int i;

    for (i = 0; i < a[u].size(); i++)
        if (a[u][i] == v)
            return true;

    for (i = 0; i < a[v].size(); i++)
        if (a[v][i] == u)
            return true;

    return false;
}

void dfs(int v, vc<vc<int>> &a, vc<char> &key, vc<bool> &visited)
{
    if (visited[v])
        return;

    cout << key[v];
    visited[v] = true;

    for (int i = a[v].size() - 1; i >= 0; i--)
        dfs(a[v][i], a, key, visited);
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
    vc<char> key(n);

    for (i = 0; i < n; i++)
        cin >> key[i];
    /** input edge */
    vc<vc<int>> a(n);

    for (i = 0; i < m; i++)
    {
        cin >> u >> v >> val;

        if (!find(a, u, v))
        {
            a[u].pb(v);
            a[v].pb(u);
        }
    }
    /** dfs */
    vc<bool> visited(n, false);

    for (i = 0; i < n; i++)
        if (!visited[i])
        {
            dfs(i, a, key, visited);
            cout << endl;
        }

    return 0;
}
