/* 本题考查并查集的find, union操作 */

/* 01和02解的区别在于是否将数组作为函数形参 */
/* 02解的实现是将数组作为全局变量 */
/* 该解只是将下标改为从1开始 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> u;

void init()
{
    for (int i = 1; i < u.size(); i++)
        u[i] = -1;
}

int find(int p)
{
    if (u[p] < 0)
        return p;

    u[p] = find(u[p]); /* 路径压缩 */

    return find(u[p]);
}

void unionByRank(int p, int q)
{
    int root1 = find(p);
    int root2 = find(q);

    if (root1 != root2)
    {
        if (u[root1] < u[root2])
        {
            u[root1] += u[root2];
            u[root2] = root1;
        }
        else
        {
            u[root2] += u[root1];
            u[root1] = root2;
        }
    }
}

bool isSameUnion(int p, int q)
{
    int root1 = find(p);
    int root2 = find(q);

    return root1 == root2;
}

int main()
{
    int i;
    int n;
    char op;
    int a, b;

    cin >> n;
    u.resize(n + 1);
    init();

    cin >> op;

    while (op != 'S')
    {
        cin >> a >> b;

        if (op == 'I')
            unionByRank(a, b);
        else if (op == 'C')
        {
            if (isSameUnion(a, b))
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }

        cin >> op;
    }

    int cnt = 0;

    for (i = 1; i <= n; i++)
        if (u[i] < 0)
            cnt++;

    if (cnt == 1)
        cout << "The network is connected." << endl;
    else
        cout << "There are " << cnt << " components." << endl;

    return 0;
}
