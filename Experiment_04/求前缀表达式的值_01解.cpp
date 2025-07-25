/** 本题的坑在于: 输入可能存在负数和小数 */

/** 01和02解的区别在于是否是函数式实现 */
/** 01解为非函数式实现 */

#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;

int main()
{
    int i, j;
    string s;
    /** Input */
    getline(cin, s);
    /** Make a stack */
    stack<double> stk;
    double a, b;

    for (i = s.size() - 1; i >= 0; i--)
    {
        if (isdigit(s[i]))
        {
            string s1;

            for (j = i; j >= 0 && (isdigit(s[j]) || s[j] == '.'); j--)
                s1 = s[j] + s1;

            if (j >= 0 && s[j] == '-')
                s1 = s[j] + s1; /** s1 = '-' + s1; */

            stk.push(stod(s1));
            i = j;
        }
        else if (s[i] == '+')
        {
            if (stk.size() < 2)
            {
                cout << "ERROR" << endl;

                return 0;
            }

            a = stk.top();
            stk.pop();
            b = stk.top();
            stk.pop();
            stk.push(a + b);
        }
        else if (s[i] == '-')
        {
            if (stk.size() < 2)
            {
                cout << "ERROR" << endl;

                return 0;
            }

            a = stk.top();
            stk.pop();
            b = stk.top();
            stk.pop();
            stk.push(a - b);
        }
        else if (s[i] == '*')
        {
            if (stk.size() < 2)
            {
                cout << "ERROR" << endl;

                return 0;
            }

            a = stk.top();
            stk.pop();
            b = stk.top();
            stk.pop();
            stk.push(a * b);
        }
        else if (s[i] == '/')
        {
            if (stk.size() < 2)
            {
                cout << "ERROR" << endl;

                return 0;
            }

            a = stk.top();
            stk.pop();
            b = stk.top();
            stk.pop();

            if (b == 0)
            {
                cout << "ERROR" << endl;

                return 0;
            }

            stk.push(a / b);
        }
    }

    if (stk.size() == 1)
        cout << fixed << setprecision(1) << stk.top() << endl;
    else
        cout << "ERROR" << endl;

    return 0;
}
