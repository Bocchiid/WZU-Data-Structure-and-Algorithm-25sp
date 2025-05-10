/** 01和02解的区别在于是否是函数式实现 */
/** 01解为非函数式(大部分)实现 */
/** 01和02解为邻接表的数组实现 */

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
/** 输出结点 */
void printVertex(vc<char> &key, int size)
{
    int i;

    for (i = 0; i < size; i++)
        cout << key[i];

    cout << endl;
}
/** 插入边 */
void insertEdge(vc<vc<pair<int, int>>> &a, int u, int v, int val)
{ /** 根据题目的意思, 本题不会出现重复输入的边, 但题目表述未提及，不严谨 */
    a[u].pb({v, val});
}
/** 判断边的存在性 */
bool edgeValid(vc<vc<pair<int, int>>> &a, int u, int v)
{
    int i;

    for (i = 0; i < a[u].size(); i++)
        if (a[u][i].first == v)
            return true;

    return false;
}
/** 获取邻接点 */
int getAdjnode(vc<vc<pair<int, int>>> &a, int v)
{ /** 按题目的意思保证一定有, 所以直接输出, 但其实不严谨 */
    return a[v][0].first;
}
/** 删除结点 */
void deleteVertex(vc<vc<pair<int, int>>> &a, vc<char> &key, int v, int &size)
{
    int i, j;

    cout << "待删除的顶点信息为 " << key[v] << endl;
    key[v] = key[size - 1]; /** 覆盖结点 */
    a[v] = a[size - 1];     /** 覆盖待删除的结点 */
    /** 结点数-1 */
    size--;
    /** 删除拥有待删除的结点的边 */
    for (i = 0; i < size; i++)
        for (j = 0; j < a[j].size();)
            if (a[i][j].first == v)
                a[i].erase(a[i].begin() + j);
            else
                j++;
    /** 修改相应邻接点 */
    for (i = 0; i < size; i++)
        for (j = 0; j < a[i].size(); j++)
            if (a[i][j].first == size)
                a[i][j].first = v;
}
/** 获取结点数 */
int countVertex(int n)
{
    return n;
}
/** 获取边数 */
int countEdge(vc<vc<pair<int, int>>> &a, int size)
{
    int i;
    int cnt = 0;

    for (i = 0; i < size; i++)
        cnt += a[i].size();

    return cnt;
}
/** 输出结点数 */
void printCountVertex(int n)
{
    cout << "顶点数 = " << countVertex(n) << endl;
}
/** 输出边的存在性 */
void printEdgeValid(vc<vc<pair<int, int>>> &a, int u, int v)
{
    cout << "<" << u << ", " << v << "> 的存在性 = ";

    if (edgeValid(a, u, v))
        cout << 1 << endl;
    else
        cout << 0 << endl;
}
/** 输出边的数量 */
void printCountEdge(vc<vc<pair<int, int>>> &a, int size)
{
    cout << "边数 = " << countEdge(a, size) << endl;
}
/** 输出邻接点 */
void printAdjnode(vc<vc<pair<int, int>>> &a, int v)
{
    cout << "顶点" << v << "的第一个邻接点 = " << getAdjnode(a, v) << endl;
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
        insertEdge(a, u, v, val); /** 根据题目的意思, 本题不会出现重复输入的边, 但题目表述未提及，不严谨 */
    }
    /** reverse edge */
    for (i = 0; i < n; i++)
        reverse(a[i].begin(), a[i].end());

    print(a, n);         /** 输出邻接表 */
    printCountVertex(n); /** 输出结点数 */
    /** 判断边的存在性 */
    for (i = 0; i < 2; i++)
    {
        cin >> u >> v;
        printEdgeValid(a, u, v);
    }
    /** 寻找点的第一个邻接点 */
    cin >> u;
    printAdjnode(a, u);
    /** 删除一个结点 */
    cin >> u;
    deleteVertex(a, key, u, n);
    /** 输出结点数 */
    cout << "当前";
    printCountVertex(n);
    /** 输出边数 */
    cout << "当前";
    printCountEdge(a, n);
    /** 输出结点 */
    printVertex(key, n);
    /** 输出邻接表 */
    print(a, n);

    return 0;
}
