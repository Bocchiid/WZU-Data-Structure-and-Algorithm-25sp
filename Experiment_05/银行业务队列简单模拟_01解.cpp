#define vc vector
#define pb push_back

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int i, j;
    int n;

    cin >> n;
    queue<int> a;
    queue<int> b;

    for (i = 0; i < n; i++)
    {
        int num;

        cin >> num;

        if (num & 1 == 1)
            a.push(num);
        else
            b.push(num);
    }

    vc<int> ans;

    while (!a.empty() || !b.empty())
    {
        if (!a.empty())
        {
            ans.pb(a.front());
            a.pop();
        }

        if (!a.empty())
        {
            ans.pb(a.front());
            a.pop();
        }

        if (!b.empty())
        {
            ans.pb(b.front());
            b.pop();
        }
    }

    for (i = 0; i < n; i++)
    {
        if (i != 0)
            cout << ' ';

        cout << ans[i];
    }

    cout << endl;

    return 0;
}
