/** 01和02解的区别在于是否是函数式实现 */
/** 01解为非函数式(大部分)实现 */

#define vc vector
#define pb push_back

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/** 输出邻接表 */
void print(vc<vc<pair<int, int>>> &a, int size)
{
    int i, j;

    cout << "邻接表为：" << endl;

    for (i = 0; i < size; i++)
    {
        cout << "list[" << i << "]";

        for (j = 0; j < a[i].size(); j++)
        {
            cout << "->" << a[i][j].first << ":" << a[i][j].second;
        }

        cout << "->end" << endl;
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
    vc<char> key(n);

    for (i = 0; i < n; i++)
        cin >> key[i];
    /** input edge */
    vc<vc<pair<int, int>>> a(n);

    for (i = 0; i < m; i++)
    {
        cin >> u >> v >> val;
        a[u].pb({v, val}); /** 根据题目的意思, 本题不会出现重复输入的边, 但题目表述未提及，不严谨 */
    }
    /** reverse edge */
    for (i = 0; i < n; i++)
        reverse(a[i].begin(), a[i].end());

    print(a, n);                      /** 输出邻接表 */
    cout << "顶点数 = " << n << endl; /** 输出结点数 */
    /** 判断边的存在性 */
    for (i = 0; i < 2; i++)
    {
        bool found = false;

        cin >> u >> v;
        cout << "<" << u << ", " << v << "> 的存在性 = ";

        for (j = 0; j < a[u].size(); j++)
            if (a[u][j].first == v)
            {
                found = true;
                break;
            }

        if (found)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    /** 寻找点的第一个邻接点 */
    cin >> u; /** 按题目的意思保证一定有, 所以直接输出, 但其实不严谨 */
    cout << "顶点" << u << "的第一个邻接点 = " << a[u][0].first << endl;
    /** 删除一个结点 */
    cin >> u;
    cout << "待删除的顶点信息为 " << key[u] << endl;
    key[u] = key[n - 1]; /** 覆盖结点 */
    /** 覆盖待删除的结点 */
    a[u] = a[n - 1];
    /** 结点数-1 */
    n--;
    /** 删除拥有待删除的结点的边 */
    for (i = 0; i < n; i++)
        for (j = 0; j < a[i].size();)
            if (a[i][j].first == u)
                a[i].erase(a[i].begin() + j);
            else
                j++;
    /** 修改相应邻接点 */
    for (i = 0; i < n; i++)
        for (j = 0; j < a[i].size(); j++)
            if (a[i][j].first == n)
                a[i][j].first = u;
    /** 输出结点数 */
    cout << "当前顶点数 = " << n << endl;
    /** 输出边数 */
    int cnt = 0;

    for (i = 0; i < n; i++)
        cnt += a[i].size();

    cout << "当前边数 = " << cnt << endl;
    /** 输出结点 */
    for (i = 0; i < n; i++)
        cout << key[i];

    cout << endl;
    /** 输出邻接表 */
    print(a, n);

    return 0;
}
