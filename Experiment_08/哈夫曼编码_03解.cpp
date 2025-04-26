/* 该解法的isprefix为暴力枚举 + 朴素匹配 */

/* 该解法的selectTwoMin的实现为顺序查找 */
/* 该解法的calWPL为sum += weight * length 实现 */

#include <iostream>
#include <vector>
using namespace std;
/* Definition of HuffmanTree Node */
struct tnode
{
    int weight;
    int parent;
    int left;
    int right;
};
/* Init HuffmanTree */
void init(vector<int> &w, vector<tnode> &a)
{
    int i;

    for (i = 0; i < w.size(); i++)
    {
        a[i].weight = w[i];
        a[i].parent = -1;
        a[i].left = a[i].right = -1;
    }

    for (i; i < a.size(); i++)
    {
        a[i].parent = -1;
        a[i].left = a[i].right = -1;
    }
}
/* SelectTwoMin Elements in HuffmanTree by Force */
void selectTwoMin(vector<tnode> &a, int size, int &m1, int &m2)
{
    int i;
    bool first = true;
    bool second = true;

    for (i = 0; i < size; i++)
    {
        if (a[i].parent == -1)
        {
            if (first)
            {
                m1 = i;
                first = false;
            }
            else
            {
                if (second)
                {
                    m2 = i;
                    second = false;
                }

                if (a[i].weight < a[m1].weight)
                {
                    m2 = m1;
                    m1 = i;
                }
                else if (a[i].weight < a[m2].weight)
                    m2 = i;
            }
        }
    }
}
/* Build a HuffmanTree */
void buildTree(vector<tnode> &a, int n)
{
    int i;
    int m1, m2;

    for (i = n; i < a.size(); i++)
    {
        selectTwoMin(a, i, m1, m2);

        a[i].weight = a[m1].weight + a[m2].weight;
        a[i].left = m1;
        a[i].right = m2;

        a[m1].parent = i;
        a[m2].parent = i;
    }
}
/* calculate WPL of HuffmanTree */
void calWPL(vector<tnode> &a, int n, int &sum)
{
    int i;
    int p;
    int length;

    for (i = 0; i < n; i++)
    {
        length = 0;
        p = i;

        while (a[p].parent != -1)
        {
            length++;
            p = a[p].parent;
        }

        sum += a[i].weight * length;
    }
}

void calWPL(vector<int> &w, vector<string> &b, int &sum1)
{
    for (int i = 0; i < b.size(); i++)
        sum1 += w[i] * b[i].size();
}

bool isprefix(vector<string> &b)
{
    int i, j;

    for (i = 0; i < b.size(); i++)
    {
        for (j = 0; j < b.size(); j++)
        {
            if (i == j)
                continue;

            if (b[i].size() > b[j].size())
                continue;

            if (b[j].find(b[i], 0) == 0)
                return false;
        }
    }

    return true;
}

int main()
{
    int i, j;
    int n;
    char c;

    cin >> n;
    vector<int> w(n);

    for (i = 0; i < n; i++)
        cin >> c >> w[i];

    vector<tnode> a(2 * n - 1);
    init(w, a);

    buildTree(a, n);

    int sum = 0;
    calWPL(a, n, sum);

    int m;
    int sum1;

    cin >> m;

    for (i = 0; i < m; i++)
    {
        vector<string> b(n);

        for (j = 0; j < n; j++)
            cin >> c >> b[j];

        sum1 = 0;
        calWPL(w, b, sum1);

        if (sum != sum1)
        {
            cout << "No" << endl;
            continue;
        }

        if (isprefix(b))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
