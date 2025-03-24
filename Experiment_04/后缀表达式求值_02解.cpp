/* 此解法为函数解法, 不习惯函数的话, 可以去看_01解 */

#include <iostream>
#include <stack>
using namespace std;

stack<int> stk;
int a, b;

bool isvalid()
{
    if (stk.size() < 2)
    {
        cout << "错误：表达式不规范。" << endl
             << 1000000000 << endl;

        return false;
    }

    return true;
}

void getTwoNum()
{
    b = stk.top();
    stk.pop();
    a = stk.top();
    stk.pop();
}

bool divisor_zero()
{
    if (b == 0)
    {
        cout << "错误：除法操作分母为零。" << endl
             << 1000000000 << endl;

        return true;
    }

    return false;
}

bool mod_zero()
{
    if (b == 0)
    {
        cout << "错误：取模操作除数为零。" << endl
             << 1000000000 << endl;

        return true;
    }

    return false;
}

bool add()
{
    if (isvalid())
    {
        getTwoNum();
        stk.push(a + b);

        return true;
    }

    return false;
}

bool sub()
{
    if (isvalid())
    {
        getTwoNum();
        stk.push(a - b);

        return true;
    }

    return false;
}

bool time()
{
    if (isvalid())
    {
        getTwoNum();
        stk.push(a * b);

        return true;
    }

    return false;
}

bool divide()
{
    if (isvalid())
    {
        getTwoNum();
        
        if (divisor_zero())
            return false;
        else
            stk.push(a / b);

        return true;
    }

    return false;
}

bool mod()
{
    if (isvalid())
    {
        getTwoNum();

        if (mod_zero())
            return false;
        else
            stk.push(a % b);

        return true;
    }

    return false;
}

int main()
{
    string s;

    while (cin >> s)
    {
        if (s == "+")
        {
            if (!add())
                return 0;
        }
        else if (s == "-")
        {
            if (!sub())
                return 0;
        }
        else if (s == "*")
        {
            if (!time())
                return 0;
        }
        else if (s == "/")
        {
            if (!divide())
                return 0;
        }
        else if (s == "%")
        {
            if (!mod())
                return 0;
        }
        else
            stk.push(stoi(s));
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
