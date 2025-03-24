#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> stk;
    string s;
    int a, b;

    while (cin >> s)
    {
        if (s == "+")
        {
            if (stk.size() < 2)
            {
                cout << "错误：表达式不规范。" << endl
                     << 1000000000 << endl;

                return 0;
            }

            b = stk.top();
            stk.pop();
            a = stk.top();
            stk.pop();
            stk.push(a + b);
        }
        else if (s == "-")
        {
            if (stk.size() < 2)
            {
                cout << "错误：表达式不规范。" << endl
                     << 1000000000 << endl;

                return 0;
            }

            b = stk.top();
            stk.pop();
            a = stk.top();
            stk.pop();
            stk.push(a - b);
        }
        else if (s == "*")
        {
            if (stk.size() < 2)
            {
                cout << "错误：表达式不规范。" << endl
                     << 1000000000 << endl;

                return 0;
            }

            b = stk.top();
            stk.pop();
            a = stk.top();
            stk.pop();
            stk.push(a * b);
        }
        else if (s == "/")
        {
            if (stk.size() < 2)
            {
                cout << "错误：表达式不规范。" << endl
                     << 1000000000 << endl;

                return 0;
            }

            b = stk.top();
            stk.pop();
            a = stk.top();
            stk.pop();

            if (b == 0)
            {
                cout << "错误：除法操作分母为零。" << endl
                     << 1000000000 << endl;

                return 0;
            }

            stk.push(a / b);
        }
        else if (s == "%")
        {
            if (stk.size() < 2)
            {
                cout << "错误：表达式不规范。" << endl
                     << 1000000000 << endl;

                return 0;
            }

            b = stk.top();
            stk.pop();
            a = stk.top();
            stk.pop();

            if (b == 0)
            {
                cout << "错误：取模操作除数为零。" << endl
                     << 1000000000 << endl;

                return 0;
            }

            stk.push(a % b);
        }
        else
        {
            stk.push(stoi(s));
        }
    }

    if (stk.size() == 1)
        cout << stk.top() << endl;
    else
    {
        cout << "错误：表达式不规范。" << endl
             << 1000000000 << endl;
    }

    return 0;
}
