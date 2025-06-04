/** 本题的坑在于: 输入里面存在小数和负数 */

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int i, j;
    string s;

    getline(cin, s);
    /** Make a stack */
    stack<char> stk;
    /** 用于格式控制 */
    bool flag = true;

    for (i = 0; i < s.size(); i++)
    {
        if (i == 0 && s[i] == '-')
        {
            string s1 = "-";

            for (j = i + 1; j < s.size() && (isdigit(s[j]) || s[j] == '.'); j++)
                s1 += s[j];

            if (!flag)
                cout << ' ';

            cout << s1;
            flag = false;

            i = j - 1;
        }
        else if (i > 0 && i < s.size() - 2 &&
                 (s[i] == '-' || s[i] == '+') &&
                 s[i - 1] == '(' && isdigit(s[i + 1]))
        {
            string s1;

            if (s[i] == '-')
                s1 = "-";

            for (j = i + 1; j < s.size() && (isdigit(s[j]) || s[j] == '.'); j++)
                s1 += s[j];

            if (!flag)
                cout << ' ';

            cout << s1;
            flag = false;

            i = j;
        }
        else if (isdigit(s[i]))
        {
            string s1;

            for (j = i; j < s.size() && (isdigit(s[j]) || s[j] == '.'); j++)
                s1 += s[j];

            if (!flag)
                cout << ' ';

            cout << s1;
            flag = false;

            i = j - 1;
        }
        else if (s[i] == '(' && i < s.size() - 1 && s[i + 1] != '+' && s[i + 1] != '-')
            stk.push(s[i]);
        else if (s[i] == ')')
        {
            while (!stk.empty() && stk.top() != '(')
            {
                if (!flag)
                    cout << ' ';

                cout << stk.top();
                flag = false;
                stk.pop();
            }

            stk.pop();
        }
        else if (s[i] == '+' || s[i] == '-')
        {
            while (!stk.empty() && stk.top() != '(')
            {
                if (!flag)
                    cout << ' ';

                cout << stk.top();
                flag = false;
                stk.pop();
            }

            stk.push(s[i]);
        }
        else if (s[i] == '*' || s[i] == '/')
        {
            while (!stk.empty() && stk.top() != '(' &&
                   stk.top() != '+' && stk.top() != '-')
            {
                if (!flag)
                    cout << ' ';

                cout << stk.top();
                flag = false;
                stk.pop();
            }

            stk.push(s[i]);
        }
    }

    while (!stk.empty())
    {
        if (!flag)
            cout << ' ';

        cout << stk.top();
        flag = false;
        stk.pop();
    }

    cout << endl;

    return 0;
}
