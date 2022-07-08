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
        for (int i = 0; i < n; i++)
        {
            vector<int> nums2;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    nums2.push_back(nums[j]);
                }
            }
            vector<vector<int>> v = helper(nums2);
            for (auto x : v)
            {
                x.push_back(nums[i]);
                ans.push_back(x);
            }
        }
        return ans;
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        return helper(nums);
    }
};