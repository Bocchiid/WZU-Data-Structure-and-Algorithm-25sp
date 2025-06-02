#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> mp;

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

    int maxt = 0;

    for (auto ele : mp)
        maxt = max(maxt, ele.second);

    string number;
    bool flag = true;

    for (auto ele : mp)
    {
        if (ele.second == maxt)
        {
            if (flag)
            {
                number = ele.first;
                flag = false;
            }
            else
                number = min(number, ele.first);
        }
    }

    cout << number << " " << maxt;

    int cnt = 0;

    for (auto ele : mp)
        if (ele.second == maxt)
            cnt++;

    if (cnt != 1)
        cout << ' ' << cnt;

    cout << endl;

    return 0;
}
