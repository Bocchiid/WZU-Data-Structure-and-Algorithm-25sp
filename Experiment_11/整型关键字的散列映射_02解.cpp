/** 01解和02解的区别在于是否是函数式实现 */
/** 02解为函数式实现 */

#define vc vector
#define pb push_back

#include <iostream>
#include <vector>
using namespace std;

int find(vc<int> &a, const int &num)
{
    int i;
    int pos = num % a.size();

    for (i = pos;; i = (i + 1) % a.size())
    {
        if (a[i] == num)
            return i;
        else if (!a[i])
            return i;
    }
}

int insert(vc<int> &a, const int &num)
{
    int pos = find(a, num);

    if (!a[pos])
        a[pos] = num;

    return pos;
}

int main()
{
    int i, j;
    int n, p;

    cin >> n >> p;
    vc<int> a(p);

    for (i = 0; i < n; i++)
    {
        int num;
        int pos;

        cin >> num;
        pos = insert(a, num);

        if (i != 0)
            cout << ' ';

        cout << pos;
    }

    cout << endl;

    return 0;
}
