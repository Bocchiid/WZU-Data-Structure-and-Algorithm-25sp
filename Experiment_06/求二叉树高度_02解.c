/* 该解法为层序遍历bfs解法 */

int GetHeight( BinTree BT )
{
    int h = 0;

    if (!BT) // if (BT == NULL)
        return h;

    BinTree q[101];
    int head = 0;
    int tail = 0;

    q[tail] = BT;
    tail++;

    while (head != tail)
    {
        int n = tail - head;
        h++;

        for (int i = 0; i < n; i++)
        {
            BinTree t = q[head];
            head++;

            if (t->Left)
            {
                q[tail] = t->Left;
                tail++;
            }

            if (t->Right)
            {
                q[tail] = t->Right;
                tail++;
            }
        }
    }

    return h;
}
