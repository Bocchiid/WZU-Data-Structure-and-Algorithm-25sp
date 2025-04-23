/* 本题考查并查集的find, union操作 */

/* 01和02解的区别在于是否将数组作为函数形参 */
/* 01解的实现是将数组作为函数形参 */

#include <iostream>
#include <vector>
using namespace std;

void init(vector<int> &u)
{
    for (int i = 0; i < u.size(); i++)
        u[i] = -1;
}

int find(vector<int> &u, int p)
{
    if (u[p] < 0)
        return p;

    u[p] = find(u, u[p]); /* 路径压缩 */

    return find(u, u[p]);
}

void unionByRank(vector<int> &u, int p, int q)
{
    int root1 = find(u, p);
    int root2 = find(u, q);

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

bool isSameUnion(vector<int> &u, int p, int q)
{
    int root1 = find(u, p);
    int root2 = find(u, q);

    return root1 == root2;
}

int main()
{
    int i;
    int n;
    char op;
    int a, b;

    cin >> n;
    vector<int> u(n);
    init(u);

    cin >> op;

    while (op != 'S')
    {
        cin >> a >> b;

        if (op == 'I')
            unionByRank(u, a - 1, b - 1);
        else if (op == 'C')
        {
            if (isSameUnion(u, a - 1, b - 1))
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }

        cin >> op;
    }

    int cnt = 0;

    for (i = 0; i < n; i++)
        if (u[i] < 0)
            cnt++;

    if (cnt == 1)
        cout << "The network is connected." << endl;
    else
        cout << "There are " << cnt << " components." << endl;

    return 0;
}
