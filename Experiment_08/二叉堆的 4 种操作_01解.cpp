/* 由于二叉堆不唯一 */
/* 本题请严格按照percolateUp(上滤/上升)调整建立二叉堆 */
/* 01和02解的区别在于是否将数组作为函数形参 */
/* 01解的实现是将数组作为函数形参 */

#include <iostream>
#include <vector>
using namespace std;

/* percolateUp()为6-1的02解实现 */
void percolateUp(vector<int> &a, int p)
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
/* percolateDown()为6-1的02解实现 */
void percolateDown(vector<int> &a, int p)
{
    int size = a.size() - 1;

    for (int i = p * 2; i <= size; i *= 2)
    {
        if (i < size && a[i] > a[i + 1])
            i++;

        if (a[i] < a[p])
        {
            swap(a[i], a[p]);
            p = i;
        }
        else
            break;
    }
}

void Delete(vector<int> &a)
{
    vector<int> temp = a;

    a.resize(a.size() - 1);

    for (int i = 2; i < a.size(); i++)
        a[i] = temp[i];

    a[1] = temp[a.size()];
    percolateDown(a, 1);
}

int main()
{
    int i, j;
    int c;
    int n;

    cin >> c;
    cin >> n;
    vector<int> a(n + 2);

    for (i = 1; i <= n; i++)
        cin >> a[i];

    int x;
    cin >> x;

    n++;
    a[n] = x;
    percolateUp(a, n);

    cout << "min = " << a[1] << endl;
    Delete(a);

    for (i = 1; i < a.size(); i++)
        cout << a[i] << endl;

    return 0;
}
