#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int i, j;
    int n, m;
    string s;

    cin >> n >> m;

    for (i = 0; i < n; i++)
    {
        cin >> s;
        stack<char> stk;

        for (j = 0; j < s.size(); j++)
        {
            if (s[j] == 'S')
            {
                if (stk.size() == m)
                    break;
                else
                    stk.push(s[j]); // stk.push('S'); 其实push什么东西都行
            }
            else if (s[j] == 'X') // else
            {
                if (stk.size() == 0)
                    break;
                else
                    stk.pop();
            }
        }

        if (stk.empty() && j == s.size())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
