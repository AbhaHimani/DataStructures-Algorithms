bool isSubsetSum(vector<int> nums, int sum)
{

    bool dp[nums.size() + 1][sum + 1];
    for (int j = 1; j < sum + 1; j++)
    {
        dp[0][j] = false;
    }
    for (int i = 0; i < nums.size() + 1; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i < nums.size() + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {

            if (nums[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j - nums[i - 1]] || dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[nums.size()][sum];
    // code here
}