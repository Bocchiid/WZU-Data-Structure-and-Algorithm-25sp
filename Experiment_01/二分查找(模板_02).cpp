// 双指针(左右指针-二分搜索/查找)(左闭右开)

int search(vector<int> &nums, int target)
{
    int left, right;
    int mid;

    left = 0;
    right = nums.size();

    while (left < right)
    {
        mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid;
    }

    return -1;
}
