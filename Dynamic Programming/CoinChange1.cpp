class Solution
{
public:
    int coinChange(vector<int> &nums, int sum)
    {
        int n = nums.size();
        int t[n + 1][sum + 1];
        memset(t, 0, sizeof(t));
        for (int i = 0; i < sum + 1; i++)
        {
            t[0][i] = INT_MAX - 1;
        }
        for (int j = 1; j < sum + 1; j++)
        {
            if (j % nums[0] == 0)
            {
                t[1][j] = j / nums[0];
            }
            else
                t[1][j] = INT_MAX - 1;
        }

        for (int i = 2; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (nums[i - 1] > j)
                {
                    t[i][j] = t[i - 1][j];
                }
                else
                {
                    t[i][j] = min(t[i - 1][j], 1 + t[i][j - nums[i - 1]]);
                }
            }
        }
        if (t[n][sum] >= INT_MAX - 1)
        {
            return -1;
        }
        return t[n][sum];
    }
};