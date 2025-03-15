#include <iostream>
using namespace std;

int main()
{
    int a, b;
    int count = 0;

    while (cin >> a >> b)
    {
        if (b == 0)
            break;

        if (count == 0)
            cout << a * b << " " << b - 1;
        else
            cout << " " << a * b << " " << b - 1;

        count++;
    }

    if (!count)
        cout << "0 0";

    cout << endl;

    return 0;
}
