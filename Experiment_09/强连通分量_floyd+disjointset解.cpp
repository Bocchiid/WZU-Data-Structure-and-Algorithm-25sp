#define vc vector

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX / 2;

void floyd(vc<vc<int>> &a, int size)
{
    int i, j, k;

    for (k = 0; k < size; k++)
        for (j = 0; j < size; j++)
            for (i = 0; i < size; i++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
}

void init(vc<int> &a, int size)
{
    int i;

    for (i = 0; i < size; i++)
        a[i] = i;
}

int find(vc<int> &a, int p)
{
    if (a[p] == p)
        return p;

    a[p] = find(a, a[p]);

    return find(a, a[p]);
}

void Union(vc<int> &a, int p, int q)
{
    int root1 = find(a, p);
    int root2 = find(a, q);

    if (root1 != root2)
    {
        a[root1] = root2;
    }
}

bool isSameUnion(vc<int> &a, int p, int q)
{
    int root1 = find(a, p);
    int root2 = find(a, q);

    return root1 == root2;
}

int main()
{
    int i, j;
    int n, m;
    int u, v;
    /** input */
    cin >> n >> m;
    vc<vc<int>> a(n, vc<int>(n, INF));
    /** 结点自身到自身的距离为0 */
    for (i = 0; i < n; i++)
    {
        j = i;
        a[i][j] = 0;
    }
    /** input edge */
    for (i = 0; i < m; i++)
    {
        cin >> u >> v;
        a[u][v] = 0; /** u到v距离不为INF(可达) */
    }
    /** floyd */
    floyd(a, n);
    /** build a Union Find Set */
    vc<int> b(n);
    init(b, n);
    /** 将结点合并成强连通分量(Union Find Set) */
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] != INF && a[j][i] != INF) /** i, j可互达 */
                Union(b, i, j);
    /** 统计强连通分量数 */
    int cnt = 0;
    /** 输出强连通分量 */
    vc<bool> visited(n, false);

    for (i = 0; i < n; i++)
    { /** 输出未访问的结点 */
        if (!visited[i])
        {
            visited[i] = true;
            cout << "{" << " " << i;
            /** 输出与结点i属于同一个强连通分量的结点j */
            for (j = 0; j < n; j++)
                if (!visited[j] && isSameUnion(b, i, j))
                {
                    visited[j] = true;
                    cout << " " << j;
                }
            /** 强连通分量数++ */
            cnt++;
            cout << " }" << endl;
        }
    }
    /** 输出强连通分量数 */
    cout << cnt << endl;

    return 0;
}
