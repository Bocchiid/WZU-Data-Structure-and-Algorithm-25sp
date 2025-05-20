/** 该解法图的存储为邻接矩阵实现 */

#define vc vector
#define pb push_back

#define INF 1000000000

#include <iostream>
#include <vector>
using namespace std;

int n, m;

vc<vc<int>> a;
vc<vc<int>> dist;
vc<vc<int>> path;

void floyd()
{
    int i, j, k;
    /** init dist */
    dist = a;
    /** init path */
    path.assign(n, vc<int>(n, -1));

    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;
                }
}

int main()
{
    int i, j, k;
    /** input */
    cin >> n >> m;
    /** input edge */
    /** init array */
    a.resize(n, vc<int>(n, INF));

    for (i = 0; i < n; i++)
    {
        j = i;
        a[i][j] = 0;
    }

    for (i = 0; i < m; i++)
    {
        int u, v, w;

        cin >> u >> v >> w;
        a[u][v] = w;
    }
    /** floyd */
    floyd();
    /** output dist */
    cout << "dist:" << endl;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << dist[i][j] << " ";
        }

        cout << endl;
    }
    /** output path */
    cout << "path:" << endl;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << path[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
