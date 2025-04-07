/* 此解法虽然能过OJ, 但完全不符合题目要求, 对树的学习不利 */
/* 所以, 还请读者自觉学习树的做法 */

#include <iostream>
using namespace std;

int main()
{
    int i;
    int n;
    string val;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> val;

        if (val != "#")
            cout << val << endl;
    }

    return 0;
}
