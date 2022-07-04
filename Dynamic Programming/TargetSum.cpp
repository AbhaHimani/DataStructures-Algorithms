class Solution
{
public:
    int count_subsets(vector<int> nums, int sum)
    {
        int n = nums.size();
        int dp[n + 1][sum + 1];

        if (n == 0)
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
                for (int j = 0; j < sum + 1; j++)
                {
                    if (nums[i - 1] > j)
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                    else if (nums[i - 1] <= j)
                    {
                        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                    }
                }
            }
        }
        return dp[n][sum];
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        // Count the number of subsets with a given difference
        // SUM(S1)-SUM(S2)= target
        // SUM(S1)+SUM(S2)= SUM(NUMS[i])
        // 2(SUM(S1))= target+SUM(NUMS[i])
        // SUM(S1)= (")/2
        if (nums.size() == 1 && max(-target, target) > nums[0])
        {
            return 0;
        }
        if (nums.size() == 1 && max(target, -target) == nums[0])
        {
            return 1;
        }

        int s = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            s = s + nums[i];
        }

        if (target == 0 && s % 2 != 0)
        {
            return 0;
        }
        if ((target + s) % 2 != 0)
        {
            return 0;
        }

        int sum = (target + s) / 2;

        if (sum < target)
        {
            return 0;
        }

        return count_subsets(nums, sum);
    }
};