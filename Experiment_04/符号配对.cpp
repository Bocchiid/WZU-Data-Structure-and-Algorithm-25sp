/** 本题的坑在于: 没有坑 */
/** 单纯就是处理起来比较麻烦 */

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

    while (s != ".")
    {
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            else if (s[i] == '/')
            {
                if (i < s.size() - 1 && s[i + 1] == '*')
                {
                    stk.push(s[i]);

                    i++;
                    stk.push(s[i]);
                }
            }
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if (stk.empty())
                {
                    cout << "NO" << endl
                         << "?-" << s[i] << endl;

                    return 0;
                }
                else
                {
                    char c = stk.top();
                    stk.pop();

                    if (c == '(' && s[i] != ')' ||
                        c == '[' && s[i] != ']' ||
                        c == '{' && s[i] != '}' ||
                        c == '*')
                    {
                        if (c != '*')
                        {
                            cout << "NO" << endl
                                 << c << "-?" << endl;

                            return 0;
                        }
                        else
                        {
                            cout << "NO" << endl
                                 << "/*-?" << endl;

                            return 0;
                        }
                    }
                }
            }
            else if (s[i] == '*')
            {
                if (i < s.size() - 1 && s[i + 1] == '/')
                {
                    if (stk.empty())
                    {
                        cout << "NO" << endl
                             << "?-*/" << endl;

                        return 0;
                    }
                    else
                    {
                        char c = stk.top();
                        stk.pop();

                        if (c == '*')
                        {
                            i++;
                            stk.pop();
                        }
                        else
                        {
                            cout << "NO" << endl
                                 << c << "-?" << endl;

                            return 0;
                        }
                    }
                }
            }
        }

        getline(cin, s);
    }

    if (stk.empty())
        cout << "YES" << endl;
    else
    {
        char c = stk.top();
        stk.pop();

        if (c == '*')
        {
            cout << "NO" << endl
                 << "/*-?" << endl;
        }
        else
        {
            cout << "NO" << endl
                 << c << "-?" << endl;
        }
    }

    return 0;
}
