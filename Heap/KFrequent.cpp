class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++; // mp of 1 keeps increasing, etc
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
        for (auto i = m.begin(); i != m.end(); i++)
        {

            minH.push({i->second, i->first}); // not i.second, it is i->second
            if (minH.size() > k)
            {
                minH.pop();
            }
        }
        vector<int> ans;
        while (!minH.empty())
        {
            ans.push_back(minH.top().second);
            minH.pop();
        }
        return ans;
    }
};