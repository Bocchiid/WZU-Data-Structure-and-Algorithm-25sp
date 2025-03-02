bool insert(vector<int> &nums, int x)
{
    if (nums.size() == MAXSIZE)
        return false;

    int i;
    int pos = 0;

    for (i = 0; i < nums.size(); i++)
        if (nums[i] == x)
            return false;
        else if (nums[i] > x)
            pos = i + 1;

    for (i = nums.size() + 1; i > pos; i--)
        nums[i] = nums[i - 1];

    nums[pos] = x;
    // nums.size()++;

    return true;
}
