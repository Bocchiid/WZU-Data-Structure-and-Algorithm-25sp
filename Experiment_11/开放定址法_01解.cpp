/** 01解和02解的区别在于是否是函数式实现 */
/** 01解为非函数式实现 */

#define vc vector
#define pb push_back

#include <iostream>
#include <vector>
using namespace std;

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
        int pos;

        cin >> num;
        pos = num % l;

        for (j = pos;; j = (j + 1) % l)
        {
            if (a[j] == num)
                break;
            else if (!a[j])
            {
                a[j] = num;
                break;
            }
        }
    }

    for (i = 0; i < l; i++)
        if (a[i])
            cout << "ht[" << i << "] = " << a[i] << endl;

    return 0;
}
