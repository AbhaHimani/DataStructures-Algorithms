class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(nums.size(), 1);

        int m = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] > nums[i])
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    m = max(m, dp[i]);
                }
            }
        }
        return m;
    }
};