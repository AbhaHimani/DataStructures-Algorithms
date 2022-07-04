class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        vector<int> v;
        for (int i = 0; i <= 1; i++)
        {
            v.push_back(1);
        }

        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        while (lo < hi)
        {
            if (nums[lo] + nums[hi] == target)
            {
                cout << nums[lo] << nums[hi];
                v[0] += lo;
                v[1] += hi;
                break;
            }
            else if (nums[lo] + nums[hi] > target)
            {
                hi--;
            }
            else
            {
                lo++;
            }
        }
        return v;
    }
};