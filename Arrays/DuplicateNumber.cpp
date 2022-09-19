<<<<<<< HEAD
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for (auto i : mp)
        {
            if (i.second > 1)
            {
                return i.first;
            }
        }
        return 0;
    }
=======
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for (auto i : mp)
        {
            if (i.second > 1)
            {
                return i.first;
            }
        }
        return 0;
    }
>>>>>>> eea3f73c4a16a3b3ca27e6fd3def95a51d2f93fe
};