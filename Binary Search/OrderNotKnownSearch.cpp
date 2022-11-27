
class Solution
{
public:
    int reverseBinarySearch(vector<int> &arr, int target)
    {
        int n = arr.size();
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
    int search(vector<int> &arr, int target)
    {
        int n = arr.size();
        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == target)
            {
                return mid;
            }
            else if (arr[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return -1;
    }
    int inArray(int target, int inArray[])
    {
        if (inArray[0] > target)
        {
            return reverseBinarySearch(inArr, target);
        }
        else if (inArray[0] < target)
        {
            return search(inArr, target);
        }

        else
        {
            return 0;
        }
        return -1;
    }
};