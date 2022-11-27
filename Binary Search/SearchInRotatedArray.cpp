class Solution
{
public:
    // find minimum index
    int findKRotation(vector<int> &arr)
    {
        int n = arr.size();
        int low = 0, high = n - 1;
        if (arr[low] <= arr[high])
            return 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int prev = (mid - 1 + n) % n;
            int next = (mid + 1) % n;

            if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
                return mid;
            else if (arr[mid] <= arr[high])
                high = mid - 1;
            else if (arr[mid] >= arr[0])
                low = mid + 1;
        }
        return -1;
    }
    int binarySearch(vector<int> &arr, int low, int high, int target)
    {
        if (high >= low)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target)
                return mid;
            else if (arr[mid] > target)
                return binarySearch(arr, low, mid - 1, target);
            else if (arr[mid] < target)
                return binarySearch(arr, mid + 1, high, target);
        }
        return -1;
    }
    int search(vector<int> &arr, int target)
    {
        int n = arr.size();
        int f = findKRotation(arr);
        if (binarySearch(arr, 0, f, target) == -1 && binarySearch(arr, f, n - 1, target) == -1)
            return -1;
        else if (binarySearch(arr, 0, f, target) == -1)
            return binarySearch(arr, f, n - 1, target);
        else
            return binarySearch(arr, 0, f, target);
    }
};