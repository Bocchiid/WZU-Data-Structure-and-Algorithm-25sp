/* 该解法的isprefix为暴力枚举 + 朴素匹配 */

/* 该解法的selectTwoMin的实现为堆排序 */
/* 该解法的calWPL为sum += weight * length 实现 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/* Definition of HuffmanTree Node */
struct tnode
{
    int weight;
    int parent;
    int left;
    int right;
    int idx;
};

struct cmp
{
    bool operator()(tnode a, tnode b)
    {
        if (a.weight > b.weight)
            return true;

        return false;
    }
};

priority_queue<tnode, vector<tnode>, cmp> pq;
/* Init HuffmanTree */
void init(vector<int> &w, vector<tnode> &a)
{
    int i;

    for (i = 0; i < w.size(); i++)
    {
        a[i].weight = w[i];
        a[i].parent = -1;
        a[i].left = a[i].right = -1;
        a[i].idx = i;

        pq.push(a[i]);
    }

    for (i; i < a.size(); i++)
    {
        a[i].parent = -1;
        a[i].left = a[i].right = -1;
    }
}
/* SelectTwoMin Elements in HuffmanTree by Force */
void selectTwoMin(tnode &m1, tnode &m2)
{
    m1 = pq.top();
    pq.pop();
    m2 = pq.top();
    pq.pop();
}
/* Build a HuffmanTree */
void buildTree(vector<tnode> &a, int n)
{
    int i;
    tnode m1, m2;

    for (i = n; i < a.size(); i++)
    {
        selectTwoMin(m1, m2);

        a[i].weight = m1.weight + m2.weight;
        a[i].left = m1.idx;
        a[i].right = m2.idx;

        a[m1.idx].parent = i;
        a[m2.idx].parent = i;

        a[i].idx = i;
        pq.push(a[i]);
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
