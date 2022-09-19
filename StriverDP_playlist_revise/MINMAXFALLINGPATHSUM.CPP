class Solution
{
public:
    int helper(vector<vector<int>> matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = matrix[0][i];
        }

        for (int rows = 1; rows < m; rows++)
        {
            vector<int> temp(n, INT_MAX);
            for (int cols = 0; cols < n; cols++)
            {
                int up = INT_MAX, left = INT_MAX, right = INT_MAX;
                up = matrix[rows][cols] + dp[rows - 1][cols];
                if (cols - 1 >= 0)
                {
                    left = matrix[rows][cols] + dp[rows - 1][cols - 1];
                }
                if (cols + 1 < n)
                {
                    right = matrix[rows][cols] + dp[rows - 1][cols + 1];
                }

                dp[rows][cols] = min(up, min(left, right));
            }
        }
        int temp = 1e9;
        for (int itr = 0; itr < n; itr++)
        {
            temp = min(temp, dp[n - 1][itr]);
        }
        return temp;
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        return helper(matrix);
    }
};