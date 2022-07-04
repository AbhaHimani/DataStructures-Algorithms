class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int t = -nums[i];
            int hi = n - 1;
            int lo = i + 1;
            while (lo < hi)
            {
                if (nums[lo] + nums[hi] == t)
                {
                    ans.push_back({nums[lo], nums[hi], nums[i]});
                    while (lo < hi && nums[lo] == nums[lo + 1])
                        lo++;
                    while (lo < hi && nums[hi] == nums[hi - 1])
                        hi--;
                    lo++;
                    hi--;
                }
                else if (nums[lo] + nums[hi] > t)
                {
                    hi--;
                }
                else
                {
                    lo++;
                }
            }
            while (i + 1 < n && nums[i + 1] == nums[i])
                i++;
        }
        return ans;
    }
};