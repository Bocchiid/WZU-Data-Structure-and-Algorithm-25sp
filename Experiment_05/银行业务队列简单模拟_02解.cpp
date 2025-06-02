#include <iostream>
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

    bool flag = true;

    while (!a.empty() || !b.empty())
    {
        if (!a.empty())
        {
            if (flag)
            {
                cout << a.front();
                flag = false;
            }
            else
                cout << ' ' << a.front();

            a.pop();
        }

        if (!a.empty())
        {
            cout << ' ' << a.front();
            a.pop();
        }

        if (!b.empty())
        {
            if (flag)
            {
                cout << b.front();
                flag = false;
            }
            else
                cout << ' ' << b.front();

            b.pop();
        }
    }

    cout << endl;

    return 0;
}
