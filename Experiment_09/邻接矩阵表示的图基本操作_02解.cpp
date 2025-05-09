/** 01和02解的区别在于是否是函数式实现 */
/** 02解为函数式实现 */

#define vc vector

#include <iostream>
#include <vector>
using namespace std;

int kMaxVertex, no_edge_value;

/** 输出矩阵 */
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
/** 输出结点 */
void printVertex(vc<char> &key, int size)
{
    int i;

    for (i = 0; i < size; i++)
        cout << key[i];

    cout << endl;
}
/** 插入边 */
void insertEdge(vc<vc<int>> &a, int u, int v, int val)
{ /** 根据题目的意思, 本题不会出现重复输入的边, 但题目表述未提及，不严谨 */
    a[u][v] = val;
}
/** 删除边 */
void deleteEdge(vc<vc<int>> &a, int u, int v)
{
    a[u][v] = no_edge_value;
}
/** 判断边的存在性 */
bool edgeValid(vc<vc<int>> &a, int u, int v)
{
    return a[u][v] != no_edge_value;
}
/** 获取邻接点 */
int getAdjnode(vc<vc<int>> &a, int v, int n)
{
    int i;

    for (i = 0; i < n; i++)
        if (a[v][i] != no_edge_value)
            return i;
}
/** 删除结点 */
void deleteVertex(vc<vc<int>> &a, vc<char> &key, int v, int &n)
{
    int i, j;

    cout << "待删除的顶点信息为 " << key[v] << endl;
    key[v] = key[n - 1]; /** 覆盖结点 */
    /** 覆盖边(列) */
    for (i = 0; i < n; i++)
        a[i][v] = a[i][n - 1];
    /** 覆盖边(行) */
    for (j = 0; j < n; j++)
        a[v][j] = a[n - 1][j];
    /** 结点数-1 */
    n--;
}
/** 获取结点数 */
int countVertex(int n)
{
    return n;
}
/** 获取边数 */
int countEdge(vc<vc<int>> &a, int n)
{
    int i, j;
    int cnt = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] != no_edge_value)
                cnt++;

    return cnt;
}
/** 输出结点数 */
void printCountVertex(int n)
{
    cout << "顶点数 = " << countVertex(n) << endl;
}
/** 输出边的存在性 */
void printEdgeValid(vc<vc<int>> &a, int u, int v)
{
    cout << "<" << u << ", " << v << "> 的存在性 = ";

    if (edgeValid(a, u, v))
        cout << 1 << endl;
    else
        cout << 0 << endl;
}
/** 输出边数 */
void printCountEdge(vc<vc<int>> &a, int n)
{
    cout << "边数 = " << countEdge(a, n) << endl;
}
/** 输出邻接点 */
void printAdjnode(vc<vc<int>> &a, int v, int n)
{
    cout << "顶点" << v << "的第一个邻接点 = " << getAdjnode(a, v, n) << endl;
}

int main()
{
    int i, j;
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
        insertEdge(a, u, v, val);
    }

    print(a, n); /** 输出矩阵 */
    printCountVertex(n); /** 输出结点数 */
    /** 输出边的存在性 */
    for (i = 0; i < 2; i++)
    {
        cin >> u >> v;
        printEdgeValid(a, u, v);
    }
    /** 输出第一个邻接点 */
    cin >> v;
    printAdjnode(a, v, n);
    /** 删除边 */
    cin >> u >> v;
    deleteEdge(a, u, v);
    printEdgeValid(a, u, v);
    /** 删除结点 */
    cin >> v;
    deleteVertex(a, key, v, n);
    /** 输出顶点数 */
    cout << "当前";
    printCountVertex(n);
    /** 输出边数 */
    cout << "当前";
    printCountEdge(a, n);
    /** 输出结点 */
    printVertex(key, n);
    /** 输出矩阵 */
    print(a, n);

    return 0;
}
