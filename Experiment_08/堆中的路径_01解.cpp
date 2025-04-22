/* 由于二叉堆不唯一 */
/* 本题请严格按照percolateUp(上滤/上升)调整建立二叉堆 */

#include <iostream>
#include <vector>
using namespace std;

void percolateUp(vector<int> &a, int k)
{
    while (k > 1)
    {
        if (a[k / 2] > a[k])
        {
            swap(a[k / 2], a[k]);
            k /= 2;
        }
        else
            break;
    }
}

void print(vector<int> a, int k)
{
    bool flag = true;

    while (k >= 1)
    {
        if (!flag)
            cout << " ";

        cout << a[k];
        k /= 2;
        flag = false;
    }

    cout << endl;
}

int main()
{
    int i;
    int n, m;

    cin >> n >> m;
    vector<int> a(n + 1);

    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        percolateUp(a, i);
    }

    int num;

    for (i = 0; i < m; i++)
    {
        cin >> num;
        print(a, num);
    }

    return 0;
}
