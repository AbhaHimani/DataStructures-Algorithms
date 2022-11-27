class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int n = letters.size();
        int low = 0;
        int end = n - 1;
        int res = 0;
        while (low <= end)
        {

            int mid = low + (end - low) / 2;
            if (letters[mid] == target)
            {
                low = mid + 1;
            }
            else if (letters[mid] < target)
            {
                low = mid + 1;
            }
            else if (letters[mid] > target)
            {
                res = mid;
                end = mid - 1;
            }
        }
        return letters[res % n];
    }
};