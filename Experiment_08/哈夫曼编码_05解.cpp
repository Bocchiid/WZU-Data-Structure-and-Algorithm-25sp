/* 该解法的isprefix为暴力枚举 + 朴素匹配 */

/* 该解法为对权值直接构非叶子结点 */
/* 该解法的calWPL为sum += 非叶子结点权值实现 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

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
    {
        cin >> c >> w[i];
        pq.push(w[i]);
    }

    int m1, m2;
    int sum = 0;

    while (pq.size() > 1)
    {
        m1 = pq.top();
        pq.pop();
        m2 = pq.top();
        pq.pop();

        pq.push(m1 + m2);
        sum += m1 + m2;
    }

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
