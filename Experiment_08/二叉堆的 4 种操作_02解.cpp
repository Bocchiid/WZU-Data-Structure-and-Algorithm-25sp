/* 由于二叉堆不唯一 */
/* 本题请严格按照percolateDown(下滤/下沉)调整建立二叉堆 */
/* 01和02解的区别在于是否将数组作为函数形参 */
/* 02解的实现是将数组作为全局变量 */

/* 注: percolateUp为函数6-1的02解实现 */
/* 注: percolateDown为函数6-1的02解实现 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> a;

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

void percolateDown(int k)
{
    int size = a.size() - 1;

    for (int i = k * 2; i <= size; i *= 2)
    {
        if (i < size && a[i] > a[i + 1])
            i++;

        if (a[i] < a[k])
        {
            swap(a[k], a[i]);
            k = i;
        }
        else
            break;
    }
}

void Delete()
{
    vector<int> temp = a;
    a.resize(a.size() - 1);

    for (int i = 1; i < a.size(); i++)
        a[i] = temp[i];

    a[1] = temp[a.size()];

    for (int i = (a.size() - 1) / 2; i >= 1; i--)
        percolateDown(i);
}

int main()
{
    int i;
    int c;
    int n;
    int x;

    cin >> c;
    cin >> n;
    a.resize(n + 2);

    for (i = 1; i <= n; i++)
        cin >> a[i];

    cin >> x;
    n++;
    a[n] = x;
    percolateUp(n);

    cout << "min = " << a[1] << endl;
    Delete();

    for (i = 1; i < a.size(); i++)
        cout << a[i] << endl;

    return 0;
}
