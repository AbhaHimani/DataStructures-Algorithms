class Solution
{
public:
    int helper(vector<vector<int>> triangle)
    {
        int m = triangle.size();
        int n = triangle[0].size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int j = 0; j < m; j++)
            dp[m - 1][j] = triangle[m - 1][j];

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                dp[i][j] = min(triangle[i][j] + dp[i + 1][j], triangle[i][j] + dp[i + 1][j + 1]);
            }
        }

        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        return helper(triangle);
    }
};