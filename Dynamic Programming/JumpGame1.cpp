class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> dp(n + 1, 0);

        if (n == 1)
        {
            return true;
        }

        for (int index = n - 2; index >= 0; index--)
        {
            if (nums[index] == 0)
                dp[index] = false;

            else if (nums[index] >= n - 1 - index)
                dp[index] = true;

            else
            {
                for (int j = 1; j <= nums[index]; j++)
                {
                    dp[index] = dp[index] || dp[index + j];
                }
            }
        }
        return dp[0];
    }
};