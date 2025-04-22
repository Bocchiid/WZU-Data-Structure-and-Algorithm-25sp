/* 由于二叉堆不唯一 */
/* 本题请严格按照percolateUp(上滤/上升)调整建立二叉堆 */
/* 01和02解的区别在于是否将数组作为函数形参 */
/* 02解的实现是将数组作为全局变量处理 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> a(1001);

void percolateUp(int k)
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

void print(int k)
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

    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        percolateUp(i);
    }

    int num;

    for (i = 0; i < m; i++)
    {
        cin >> num;
        print(num);
    }

    return 0;
}
