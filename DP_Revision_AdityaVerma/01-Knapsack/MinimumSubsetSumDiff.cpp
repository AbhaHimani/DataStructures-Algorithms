class Solution
{

public:
    int minDifference(int nums[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {

            sum += nums[i];
        }

        bool dp[n + 1][sum + 1];
        for (int j = 1; j < sum + 1; j++)
        {
            dp[0][j] = false;
        }
        for (int i = 0; i < n + 1; i++)
        {
            dp[i][0] = true;
        }

        for (int i = 1; i < n + 1; i++)
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

        int mn = 99999999;

        for (int i = sum / 2; i >= 0; i--)
        {
            if (dp[n][i] == true)
            {
                mn = min(mn, sum - 2 * i);
            }
        }
        return mn;
        // Your code goes here
    }
};