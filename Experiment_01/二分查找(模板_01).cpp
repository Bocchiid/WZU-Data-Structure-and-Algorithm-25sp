// 双指针(左右指针-二分搜索/查找)(左闭右闭)

int search(vector<int> &nums, int target)
{
    int left, right;
    int mid;

    left = 0;
    right = nums.size() - 1;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
    }

    return -1;
}
