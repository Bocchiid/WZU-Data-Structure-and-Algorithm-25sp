// 双指针(快慢指针)解法

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
using namespace std;

int main()
{
    ll i;
    ll n;
    ll slow, fast;

    slow = 0, fast = 0;
    cin >> n;
    vc<ll> a(n);
    vc<ll> b(n);

    for (auto &ele : a)
        cin >> ele;

    for (auto &ele : b)
        cin >> ele;

    while ((slow + fast) < (n * 2 - 1) / 2)
    {
        if (a[fast] < b[slow])
            fast++;
        else
            slow++;
    }

    cout << min(a[fast], b[slow]) << endl;

    return 0;
}
