/** 01和02解的区别在于是否是函数式实现 */
/** 01解为非函数式(大部分)实现 */

#define vc vector

#include <iostream>
#include <vector>
using namespace std;

void print(vc<vc<int>> &a, int size)
{
    int i, j;

    cout << "邻接矩阵为：" << endl;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
            cout << a[i][j] << " ";

        cout << endl;
    }
}

int main()
{
    int i, j;
    int kMaxVertex, no_edge_value;
    int n, m;
    int u, v, val;
    /** input */
    cin >> kMaxVertex >> no_edge_value;
    cin >> n >> m;

    vc<char> key(n);

    for (i = 0; i < n; i++)
        cin >> key[i];

    vc<vc<int>> a(n, vc<int>(n, no_edge_value));

    for (i = 0; i < m; i++)
    {
        cin >> u >> v >> val;
        a[u][v] = val;
    }

    print(a, n); /** 输出矩阵 */
    cout << "顶点数 = " << n << endl; /** 输出结点数 */
    /** 判断边的存在性 */
    for (i = 0; i < 2; i++)
    {
        cin >> u >> v;
        cout << "<" << u << ", " << v << "> 的存在性 = ";

        if (a[u][v] != no_edge_value)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    /** 寻找点的第一个邻接点 */
    cin >> u;
    cout << "顶点" << u << "的第一个邻接点 = ";

    for (i = 0; i < n; i++)
        if (a[u][i] != no_edge_value)
        {
            cout << i << endl;
            break;
        }
    /** 删除一条边 */
    cin >> u >> v;
    a[u][v] = no_edge_value;
    cout << "<" << u << ", " << v << "> 的存在性 = ";

    if (a[u][v] != no_edge_value)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    /** 删除一个结点 */
    int c;

    cin >> c;
    cout << "待删除的顶点信息为 " << key[c] << endl;
    key[c] = key[n - 1]; /** 覆盖结点 */
    /** 覆盖边(列) */
    for (i = 0; i < n; i++)
        a[i][c] = a[i][n - 1];
    /** 覆盖边(行) */
    for (j = 0; j < n; j++)
        a[c][j] = a[n - 1][j];
    /** 结点数-1 */
    n--;
    cout << "当前顶点数 = " << n << endl; /** 输出结点数 */
    /** 输出边数 */
    int cnt = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] != no_edge_value)
                cnt++;

    cout << "当前边数 = " << cnt << endl;
    /** 输出结点 */
    for (i = 0; i < n; i++)
        cout << key[i];

    cout << endl;
    print(a, n); /** 输出矩阵 */

    return 0;
}
