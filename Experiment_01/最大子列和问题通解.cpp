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
    ll k;
    ll a;
    ll thissum;
    ll maxsum;

    cin >> k;
    cin >> a;
    maxsum = thissum = a;

    for (i = 1; i < k; i++)
    {
        cin >> a;
        thissum = max(thissum + a, a);
        maxsum = max(maxsum, thissum);
    }

    cout << maxsum << endl;

    return 0;
}