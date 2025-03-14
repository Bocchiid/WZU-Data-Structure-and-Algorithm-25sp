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

    cin >> n;
    vc<ll> a(n);

    for (auto &ele : a)
        cin >> ele;

    ll length = 1;
    ll maxlength = 1;
    ll start = 0;

    for (i = 1; i < n; i++)
        if (a[i] > a[i - 1])
            length++;
        else
        {
            if (length > maxlength)
            {
                maxlength = length;
                start = i - maxlength;
            }

            length = 1;
        }

    if (length > maxlength)
    {
        maxlength = length;
        start = i - maxlength;
    }

    for (i = start; i < start + maxlength; i++)
    {
        if (i != start)
            cout << " ";

        cout << a[i];
    }

    cout << endl;

    return 0;
}
