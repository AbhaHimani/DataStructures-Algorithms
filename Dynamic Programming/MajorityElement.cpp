class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        for (auto it : m)
        {
            if (it.second > n / 2)
            {
                return it.first;
            }
        }
        return 0;
    }
};