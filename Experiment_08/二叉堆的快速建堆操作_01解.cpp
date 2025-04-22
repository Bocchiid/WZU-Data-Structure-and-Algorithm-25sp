/* 由于二叉堆不唯一 */
/* 本题请严格按照percolateDown(下滤/下沉)调整建立二叉堆 */
/* 01和02解的区别在于是否将数组作为函数形参 */
/* 01解的实现是将数组作为形参处理 */

/* 注: percolateDown为函数6-1的02解实现 */

#include <iostream>
#include <vector>
using namespace std;

void percolateDown(vector<int> &a, int k)
{
    int size = a.size() - 1;

    for (int i = k * 2; i <= size; i *= 2)
    {
        if (i < size && a[i] > a[i + 1])
            i++;

        if (a[i] < a[k])
        {
            swap(a[i], a[k]);
            k = i;
        }
        else
            break;
    }
}

int main()
{
    int i;
    int c;
    int n;

    cin >> c;
    cin >> n;
    vector<int> a(n + 1);

    for (i = 1; i <= n; i++)
        cin >> a[i];

    for (i = n / 2; i >= 1; i--)
        percolateDown(a, i);

    for (i = 1; i <= n; i++)
        cout << a[i] << endl;

    return 0;
}
