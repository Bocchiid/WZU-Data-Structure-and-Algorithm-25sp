#define vc vector
#define pb push_back
#define ll long long
#define ull unsigned long long
using ld = long double;

#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;
// 请忽略臃肿的头文件
/*
Main Idea: 贪心+dp
Approach:
1. 初始化thissum = 0, maxsum = 0
2. 每次比较(thissum + a) 和 (a), 取大的一个为thissum
3. 每次比较(thissum) 和 (maxsum), 取得maxsum的最大值
Interpretation:
1. 因为要求最大子列和, 我们不妨这样想
2. thissum + a 和 a是我们下次开始可以选择的起点
3. 如果thissum + a 比 a 小, 那最大子列和应该从a开始, 即应该抛弃掉负数多的子列
*/
int main()
{
    ll i;
    ll k; // the number of integer 
    ll a; // integer itself
    ll thissum = 0; // current sum
    ll maxsum = 0; // maxsum

    cin >> k; // read in k

    for (i = 0; i < k; i++) // k times to read in a
    {
        cin >> a; // read in a
        thissum = max(thissum + a, a); // choose between (thissum + a) and (a)
        maxsum = max(maxsum, thissum); // do maxsum
    }

    cout << maxsum << endl; // output maxsum

    return 0;
}
