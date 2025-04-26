/* 该解法的selectTwoMin的实现为顺序查找 */
/* 该解法的calWPL为sum += weight * length 实现 */

#include <iostream>
#include <vector>
using namespace std;
/* Definition of HuffmanTree Node */
struct tnode
{
    int weight;
    int parent;
    int left;
    int right;
};
/* Init HuffmanTree */
void init(vector<int> &w, vector<tnode> &a)
{
    int i;

    for (i = 0; i < w.size(); i++)
    {
        a[i].weight = w[i];
        a[i].parent = -1;
        a[i].left = a[i].right = -1;
    }

    for (i; i < a.size(); i++)
    {
        a[i].parent = -1;
        a[i].left = a[i].right = -1;
    }
}
/* SelectTwoMin Elements in HuffmanTree by Force */
void selectTwoMin(vector<tnode> &a, int size, int &m1, int &m2)
{
    int i;
    bool first = true;
    bool second = true;

    for (i = 0; i < size; i++)
    {
        if (a[i].parent == -1)
        {
            if (first)
            {
                m1 = i;
                first = false;
            }
            else
            {
                if (second)
                {
                    m2 = i;
                    second = false;
                }

                if (a[i].weight < a[m1].weight)
                {
                    m2 = m1;
                    m1 = i;
                }
                else if (a[i].weight < a[m2].weight)
                    m2 = i;
            }
        }
    }
}
/* Build a HuffmanTree */
void buildTree(vector<tnode> &a, int n)
{
    int i;
    int m1, m2;

    for (i = n; i < a.size(); i++)
    {
        selectTwoMin(a, i, m1, m2);

        a[i].weight = a[m1].weight + a[m2].weight;
        a[i].left = m1;
        a[i].right = m2;

        a[m1].parent = i;
        a[m2].parent = i;
    }
}
/* calculate WPL of HuffmanTree */
void calWPL(vector<tnode> &a, int n, int &sum)
{
    int i;
    int p;
    int length;

    for (i = 0; i < n; i++)
    {
        length = 0;
        p = i;

        while (a[p].parent != -1)
        {
            length++;
            p = a[p].parent;
        }

        sum += a[i].weight * length;
    }
}

int main()
{
    int i, j;
    int n;

    cin >> n;
    vector<int> w(n);

    for (i = 0; i < n; i++)
        cin >> w[i];

    vector<tnode> a(2 * n - 1);
    init(w, a);

    buildTree(a, n);

    int sum = 0;
    calWPL(a, n, sum);
    cout << sum << endl;

    return 0;
}
