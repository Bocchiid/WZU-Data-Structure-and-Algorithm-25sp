#include <iostream>
#include <vector>
using namespace std;

struct ht
{
    int weight;
    int parent;
    int left;
    int right;
};

int main()
{
    int i, j;
    int n;
    char c;

    cin >> n;
    vector<int> a(n);

    for (i = 0; i < n; i++)
        cin >> c >> a[i];

    vector<ht> tree(2 * n - 1);

    for (i = 0; i < n; i++)
    {
        tree[i].weight = a[i];
        tree[i].parent = -1;
        tree[i].left = tree[i].right = -1;
    }

    for (i = n; i < 2 * n - 1; i++)
    {
        tree[i].parent = -1;
        tree[i].left = tree[i].right = -1;
    }

    for (i = n; i < 2 * n - 1; i++)
    {
        int m1, m2;
        bool first = true;
        bool second = true;

        for (j = 0; j < i; j++)
        {
            if (tree[j].parent == -1)
            {
                if (first)
                {
                    m1 = j;
                    first = false;
                }
                else
                {
                    if (second)
                    {
                        m2 = j;
                        second = false;
                    }

                    if (tree[j].weight < tree[m1].weight)
                    {
                        m2 = m1;
                        m1 = j;
                    }
                    else if (tree[j].weight < tree[m2].weight)
                    {
                        m2 = j;
                    }
                }
            }
        }

        tree[i].weight = tree[m1].weight + tree[m2].weight;
        tree[i].left = m1;
        tree[i].right = m2;
        tree[m1].parent = i;
        tree[m2].parent = i;
    }

    // for (auto ele : tree)
    //     cout << ele.parent << " ";

    // cout << endl;

    int sum = 0;
    int length;
    int p;

    for (i = 0; i < n; i++)
    {
        length = 0;
        p = i;

        while (tree[p].parent != -1)
        {
            length++;
            p = tree[p].parent;
        }

        sum += a[i] * length;
    }

    //cout << sum << endl;

    int m;
    int sum1;

    cin >> m;

    for (i = 0; i < m; i++)
    {
        vector<string> b(n);

        for (j = 0; j < n; j++)
            cin >> c >> b[j];

        sum1 = 0;

        for (j = 0; j < n; j++)
            sum1 += a[j] * b[j].size();

        if (sum1 != sum)
        {
            cout << "No" << endl;
            continue;
        }

        bool flag = true;

        for (int i = 0; flag && i < n; i++)
        {
            for (int j = 0; flag && j < n; j++)
            {
                if (i == j)
                    continue;

                if (b[i].size() > b[j].size())
                    continue;

                if (b[j].substr(0, b[i].size()) == b[i])
                {
                    flag = false;
                    break;
                }
            }
        }

        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
