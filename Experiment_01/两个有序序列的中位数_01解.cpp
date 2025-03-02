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
    ll n;

    cin >> n;
    vc<ll> a(n * 2);

    for (auto &ele : a)
        cin >> ele;

    sort(a.begin(), a.end());
    cout << a[(a.size() -1) / 2] << endl;

    return 0;
}
