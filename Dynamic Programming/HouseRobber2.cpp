class Solution
{
public:
    int helper(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 2)
        {
            return max(nums[0], nums[1]);
        }

        int dp[n];
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            int left = nums[i];
            int right;
            if (i > 1)
                left += dp[i - 2];
            cout << left;
            right = 0 + dp[i - 1];
            dp[i] = max(left, right);
        }
        return dp[n - 1];
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp1;
        vector<int> temp2;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
            {
                temp1.push_back(nums[i]);
            }
            if (i != n - 1)
            {
                temp2.push_back(nums[i]);
            }
        }
        return max(helper(temp1), helper(temp2));
    }
};