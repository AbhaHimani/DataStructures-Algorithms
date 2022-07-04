class Solution
{
public:
    int change(int sum, vector<int> &nums)
    {
        int n = nums.size();
        int dp[n + 1][sum + 1];
        if (sum == 0)
        {
            return 1;
        }
        else if (n == 0)
        {
            return 0;
        }
        else
        {
            for (int i = 0; i < n + 1; i++)
            {
                dp[i][0] = 1;
            }
            for (int i = 1; i < sum + 1; i++)
            {
                dp[0][i] = 0;
            }
            for (int i = 1; i < n + 1; i++)
            {
                for (int j = 1; j < sum + 1; j++)
                {
                    if (nums[i - 1] > j)
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j] + dp[i][j - nums[i - 1]];
                    }
                }
            }
        }
        return dp[n][sum];
    }
};