/** 01解和02解的区别在于是否是函数式实现 */
/** 02解为函数式实现 */

#define vc vector
#define pb push_back

#include <iostream>
#include <vector>
using namespace std;

int find(vc<int> &a, int num)
{
    int i;
    int pos;

    pos = num % a.size();

    for (i = pos;; i = (i + 1) % a.size())
    {
        if (a[i] == num)
            return -1;
        else if (!a[i])
            return i;
    }
}

void insert(vc<int> &a, int num)
{
    int pos = find(a, num);

    if (pos != -1)
        a[pos] = num;
}

int main()
{
    int i, j;
    int l;
    int n;

    cin >> l;
    vc<int> a(l);

    cin >> n;

    for (i = 0; i < n; i++)
    {
        int num;

        cin >> num;
        insert(a, num);
    }

    for (i = 0; i < l; i++)
        if (a[i])
            cout << "ht[" << i << "] = " << a[i] << endl;

    return 0;
}
