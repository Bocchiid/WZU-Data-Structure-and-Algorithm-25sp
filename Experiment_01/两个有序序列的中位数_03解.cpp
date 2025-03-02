// multiset解法

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
    ll num;
    ll cnt = 0;
    multiset<ll> st;

    cin >> n;

    for (i = 0; i < n * 2; i++)
    {
        cin >> num;
        st.insert(num);
    }

    for (auto it = st.begin(); it != st.end(); it++)
    {
        if (cnt == (st.size() - 1) / 2)
        {
            cout << *it << endl;
            break;
        }

        cnt++;
    }

    return 0;
}
