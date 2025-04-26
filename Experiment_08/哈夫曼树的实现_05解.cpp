/* 该解法为对权值直接构非叶子结点 */
/* 该解法的calWPL为sum += 非叶子结点权值实现 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    int i, j;
    int n;

    cin >> n;
    int w;

    for (i = 0; i < n; i++)
    {
        cin >> w;
        pq.push(w);
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

    cout << sum << endl;

    return 0;
}
