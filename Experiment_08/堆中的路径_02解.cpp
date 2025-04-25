/* 由于二叉堆不唯一 */
/* 本题请严格按照percolateUp(上滤/上升)调整建立二叉堆 */
/* 01和02解的区别在于是否将数组作为函数形参 */
/* 01解的实现是将数组作为全局变量 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
/* percolateUp()为6-1的02解实现 */
void percolateUp(int p)
{
    while (p > 1)
    {
        if (a[p / 2] > a[p])
        {
            swap(a[p / 2], a[p]);
            p /= 2;
        }
        else
            break;
    }
}

void print(int p)
{
    bool flag = true; /* 用于格式控制 */
    
    while (p >= 1)
    {
        if (!flag)
            cout << " ";

        cout << a[p];
        flag = false;
        p /= 2;
    }

    cout << endl;
}

int main()
{
    int i, j;
    int n, m;

    cin >> n >> m;
    a.resize(n + 1);

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
