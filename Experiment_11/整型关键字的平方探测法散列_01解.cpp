/** 01解和02解的区别在于是否是函数式实现 */
/** 01解为非函数式实现 */

#define vc vector
#define pb push_back

#include <iostream>
#include <vector>
using namespace std;

bool isprime(int x)
{
    int i;

    if (x <= 1)
        return false;

    for (i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;

    return true;
}

int minPrime(int x)
{
    int i;

    for (i = x + 1;; i++)
        if (isprime(i))
            return i;
}

int main()
{
    int i, j;
    int MSize, N;

    cin >> MSize >> N;

    int l = minPrime(MSize);
    vc<int> a(l);

    for (i = 0; i < N; i++)
    {
        int num;
        int pos;
        int cnt;

        cin >> num;
        pos = num % l;
        cnt = 0;

        for (j = pos; cnt != l; j = (pos + cnt * cnt) % l)
        {
            if (!a[j])
            {
                a[j] = num;
                break;
            }

            cnt++;
        }

        if (i != 0)
            cout << ' ';

        if (cnt != l)
            cout << j;
        else
            cout << '-';
    }

    cout << endl;

    return 0;
}
