#include <iostream>
#include <map>
using namespace std;

map<string, int> mp;

int main()
{
    int i, j;
    int n;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        string s1, s2;

        cin >> s1 >> s2;
        mp[s1]++;
        mp[s2]++;
    }

    map<string, int>::iterator it;
    int maxt = 0;

    for (it = mp.begin(); it != mp.end(); it++)
        maxt = max(maxt, it->second);

    for (it = mp.begin(); it != mp.end(); it++)
        if (it->second == maxt)
        {
            cout << it->first << ' ' << maxt;
            break;
        }

    int cnt = 0;

    for (it = mp.begin(); it != mp.end(); it++)
        if (it->second == maxt)
            cnt++;

    if (cnt != 1)
        cout << ' ' << cnt;

    cout << endl;

    return 0;
}
