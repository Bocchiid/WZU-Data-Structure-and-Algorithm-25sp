/* 题目描述中的零多项式指的是最后的答案多项式为0, 然后输出0 0 */
/* 该题为PAT乙级原题 */
/* 这里介绍一种很精美的解法 */

#include <iostream>
using namespace std;

int main()
{
    int a, b, count = 0;

    while (scanf("%d %d", &a, &b) != EOF)
    {
        if (b == 0) // 常数c求导后的结果为0
            break;

        if (count++ == 0) // 格式控制, 同时排除零多项式的情况
            cout << a * b << " " << b - 1;
        else
            cout << " " << a * b << " " << b - 1;
    }

    if (!count) // 零多项式的情况
        cout << "0 0";

    cout << endl;

    return 0;
}
