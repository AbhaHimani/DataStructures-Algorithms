int reverseBinarySearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (target == arr[mid])
        {
            return mid;
        }
        else if (target < arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}