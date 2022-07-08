class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {

        int m = grid.size();    // row
        int n = grid[0].size(); // column
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        if (m == 0)
            return 0;

        dp[0][0] = grid[0][0];
        for (int i = 1; i < n; i++)
            dp[0][i] = dp[0][i - 1] + grid[0][i];

        for (int i = 1; i < m; i++)
            dp[i][0] = dp[i - 1][0] + grid[i][0];

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                int right = grid[i][j] + dp[i - 1][j];
                int down = grid[i][j] + dp[i][j - 1];
                dp[i][j] = min(right, down);
            }
        }
        return dp[m - 1][n - 1];
    }
};