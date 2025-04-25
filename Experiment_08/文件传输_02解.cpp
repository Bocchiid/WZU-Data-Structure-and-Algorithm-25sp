/* 本题考查并查集的find, union操作 */

/* 01和02解的区别在于是否将数组作为函数形参 */
/* 02解的实现是将数组作为全局变量 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> a;

void init()
{
    for (int i = 1; i < a.size(); i++)
        a[i] = -1;
}

int find(int p)
{
    if (a[p] < 0)
        return p;

    a[p] = find(a[p]); /* 路径压缩 */

    return find(a[p]);
}
/* 按秩(rank)合并 */
void unionByRank(int p, int q)
{ /* 此处以树的元素个数为秩 */
    int root1 = find(p);
    int root2 = find(q);

    if (root1 != root2)
    {
        if (a[root1] < a[root2])
        {
            a[root1] += a[root2];
            a[root2] = root1;
        }
        else
        {
            a[root2] += a[root1];
            a[root1] = root2;
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
    int i, j;
    int n;

    cin >> n;
    a.resize(n + 1);
    init();

    char op;
    cin >> op;

    int c1, c2;

    while (op != 'S')
    {
        cin >> c1 >> c2;

        if (op == 'I')
            unionByRank(c1, c2);
        else if (op == 'C')
            if (isSameUnion(c1, c2))
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        
        cin >> op;
    }

    int cnt = 0;

    for (i = 1; i < a.size(); i++)
        if (a[i] < 0)
            cnt++;

    if (cnt == 1)
        cout << "The network is connected." << endl;
    else
        cout << "There are " << cnt << " components." << endl;

    return 0;
}
