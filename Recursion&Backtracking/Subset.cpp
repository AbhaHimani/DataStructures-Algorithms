class Solution
{
public:
    vector<vector<int>> helper(vector<int> nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return {{}};
        }

        vector<vector<int>> ans;
        vector<vector<int>> dp;

        ans.push_back({});
        for (int i = n - 1; i >= 0; i--)
        {
            vector<int> m;

            for (int j = i + 1; j < n; j++)
            {
                m.push_back(nums[j]);
            }

            vector<vector<int>> v = helper(m);
            for (auto x : v)
            {
                x.push_back(nums[i]);
                ans.push_back(x);
            }
        }

        return ans;
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {

        return helper(nums);
    }
};