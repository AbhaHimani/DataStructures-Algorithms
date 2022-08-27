class Solution
{
public:
    int helper(vector<int> nums)
    {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int n = nums.size();
        if (n == 2)
        {
            return max(nums[0], nums[1]);
        }
        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            int notPick = 0;
            if (i > 1)
            {
                pick += dp[i - 2];
            }
            notPick += dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        return dp[n - 1];
    }
    int rob(vector<int> &nums)
    {

        return helper(nums);
    }
};