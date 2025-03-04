// 最长连续递增子序列(求序列)

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
    ll maxlength = 0;

    cin >> n;
    vc<ll> a(n);
    vc<ll> ans;

    for (auto &ele : a)
        cin >> ele;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[j] > a[j - 1])
                length++;
            else
            {
                if (length > maxlength)
                {
                    maxlength = length;
                    ans.clear();

                    for (j = i; j < i + maxlength; j++)
                        ans.pb(a[j]);
                }

                length = 1;
                i = j - 1;
                break;
            }
        }

        if (j == n)
            break;
    }

    if (length > maxlength)
    {
        maxlength = length;
        ans.clear();

        for (j = i; j < i + maxlength; j++)
            ans.pb(a[j]);
    }

    for (i = 0; i < maxlength; i++)
    {
        if (i > 0)
            cout << ' ';

        cout << ans[i];
    }

    cout << endl;

    return 0;
}
