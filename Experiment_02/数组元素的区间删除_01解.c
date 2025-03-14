/* 双指针(快慢指针) 解法 */

int Delete( int A[], int L, int minA, int maxA )
{
    int slow, fast;

    slow = fast = 0;

    while (fast < L)
    {
        if (A[fast] <= minA || A[fast] >= maxA)
        {
            A[slow] = A[fast];
            slow++;
        }

        fast++;
    }

    return slow;
}
