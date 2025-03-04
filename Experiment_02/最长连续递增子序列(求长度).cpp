// 最长连续递增子序列(求长度)

#define vc vector
#define pb push_back
#define ll long long
#define ull unsigned long long
using ld = long double;

#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <iterator>
using namespace std;

int main()
{
    ll i, j;
    ll n;
    ll length = 1;
    ll maxlength = 1;

    cin >> n;
    vc<ll> a(n);

    for (auto &ele : a)
        cin >> ele;

    for (i = 1; i < n; i++)
        if (a[i] > a[i - 1])
            length++;
        else
        {
            maxlength = max(maxlength, length);
            length = 1;
        }

    maxlength = max(maxlength, length);
    cout << maxlength << endl;

    return 0;
}
