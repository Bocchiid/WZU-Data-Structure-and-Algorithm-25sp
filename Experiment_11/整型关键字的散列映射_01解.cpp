/** 奇数解和偶数解的区别在于是否是函数式实现 */
/** 01解为非函数式实现 */

#define vc vector
#define pb push_back

#include <iostream>
#include <vector>
using namespace std;

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
        pos = num % p;

        for (j = pos;; j = (j + 1) % p)
        {
            if (a[j] == num)
                break;
            else if (!a[j])
            {
                a[j] = num;
                break;
            }
        }

        if (i != 0)
            cout << ' ';

        cout << j;
    }

    cout << endl;

    return 0;
}
