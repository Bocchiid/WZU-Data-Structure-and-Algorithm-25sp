/* 由于二叉堆不唯一 */
/* 本题请严格按照percolateDown(下滤/下沉)调整建立二叉堆 */
/* 01和02解的区别在于是否将数组作为函数形参 */
/* 02解的实现是将数组作为全局变量 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
/* percolateDown()为6-1的02解实现 */
void percolateDown(int p)
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

int main()
{
    int i, j;
    int c;
    int n;

    cin >> c;
    cin >> n;
    a.resize(n + 1);

    for (i = 1; i <= n; i++)
        cin >> a[i];

    for (i = n / 2; i >= 1; i--)
        percolateDown(i);

    for (i = 1; i <= n; i++)
        cout << a[i] << endl;

    return 0;
}
