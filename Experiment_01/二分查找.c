Position BinarySearch(List L, ElementType X)
{
    Position left, right;
    Position mid;

    left = 1;
    right = L->Last;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (L->Data[mid] == X)
            return mid;
        else if (L->Data[mid] < X)
            left = mid + 1;
        else if (L->Data[mid] > X)
            right = mid - 1;
    }

    return NotFound;
}
