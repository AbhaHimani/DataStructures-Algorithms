class Solution
{
public:
    bool subset_sum(vector<int> nums, int sum)
    {
        int n = nums.size();
        bool subset[n + 1][sum + 1];
        if (sum == 0)
        {
            return true;
        }
        else if (n == 0)
        {
            return false;
        }
        else
        {
            for (int j = 0; j < nums.size() + 1; j++)
            {
                subset[j][0] = true;
            }
            for (int i = 1; i < sum + 1; i++)
            {
                subset[0][i] = false;
            }
            for (int i = 1; i < nums.size() + 1; i++)
            {
                for (int j = 1; j < sum + 1; j++)
                {
                    if (nums[i - 1] > j)
                    {
                        subset[i][j] = subset[i - 1][j];
                    }
                    if (nums[i - 1] <= j)
                    {
                        subset[i][j] = (subset[i - 1][j] || subset[i - 1][j - nums[i - 1]]);
                    }
                }
            }
        }
        return subset[n][sum];
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2 != 0)
        { // 23 ko 11.5 11.5 karke divide nai kar sakte
            return false;
        }
        else
        {
            sum = sum / 2;
            return subset_sum(nums, sum);
            // now it becomes a subset sum problem
        }
    }
};