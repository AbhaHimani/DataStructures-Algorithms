<<<<<<< HEAD
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int r = 0, c = m - 1;

        while (r < n && c >= 0)
        {
            if (matrix[r][c] > target)
            {
                c--;
            }
            else if (matrix[r][c] == target)
            {
                return true;
            }
            else
            {
                r++;
            }
        }
        return false;
    }
=======
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int r = 0, c = m - 1;

        while (r < n && c >= 0)
        {
            if (matrix[r][c] > target)
            {
                c--;
            }
            else if (matrix[r][c] == target)
            {
                return true;
            }
            else
            {
                r++;
            }
        }
        return false;
    }
>>>>>>> eea3f73c4a16a3b3ca27e6fd3def95a51d2f93fe
};