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

int find(vc<int> &a, const int &num, int &cnt)
{
    int i;
    int pos = num % a.size();
    cnt = 0;

    for (i = pos; cnt != a.size(); i = (pos + cnt * cnt) % a.size())
    {
        if (!a[i])
            break;

        cnt++;
    }

    return i;
}

void insert(vc<int> &a, const int &num, int &pos, int &cnt)
{
    pos = find(a, num, cnt);

    if (cnt != a.size())
        a[pos] = num;
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
        insert(a, num, pos, cnt);

        if (i != 0)
            cout << ' ';

        if (cnt != l)
            cout << pos;
        else
            cout << '-';
    }

    cout << endl;

    return 0;
}
