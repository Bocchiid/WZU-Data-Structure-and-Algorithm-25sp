#include <stdio.h>
/* 善用typedef, 日后你会感谢自己的这个习惯的 */
typedef struct tnode
{
    int val;
    int left;
    int right;
} tnode;

int main()
{
    int i;
    int n;

    tnode a[101];         /* 用于存放树结点 */
    int check[101] = {0}; /* 用于找根的位置 */

    scanf("%d", &n);
    getchar(); /* C的老毛病了, 把缓冲区的换行符清理下 */
    /* 构建二叉树 */
    for (i = 0; i < n; i++)
    {
        char s[101];

        gets(s);

        char left, right;

        left = s[0];
        right = s[2];

        a[i].val = i;

        if (left != '-')
        {
            a[i].left = left - '0';
            check[a[i].left] = 1;
        }
        else
            a[i].left = -1;

        if (right != '-')
        {
            a[i].right = right - '0';
            check[a[i].right] = 1;
        }
        else
            a[i].right = -1;
    }
    /* 找二叉树的根结点的位置 */
    int root;

    for (i = 0; i < n; i++)
        if (!check[i])
        {
            root = i;
            break;
        }
    /* 层序遍历bfs */
    tnode q[101];
    int head = 0;
    int tail = 0;
    int flag = 1; /* 用于格式控制 */

    q[tail] = a[root];
    tail++;

    while (head != tail)
    {
        int n = tail - head;

        for (i = 0; i < n; i++)
        {
            tnode t = q[head];
            head++;

            if (t.left == -1 && t.right == -1)
            {
                if (flag)
                {
                    printf("%d", t.val);
                    flag = 0;
                }
                else
                    printf(" %d", t.val);
            }

            if (t.left != -1)
            {
                q[tail] = a[t.left];
                tail++;
            }

            if (t.right != -1)
            {
                q[tail] = a[t.right];
                tail++;
            }
        }
    }

    printf("\n");

    return 0;
}
