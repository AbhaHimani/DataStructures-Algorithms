class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> minH;

        for (int i = 0; i < nums.size(); i++)
        {
            minH.push(nums[i]);
        }
        while (!minH.empty())
        {
            ans.push_back(minH.top());
            minH.pop();
        }
        return ans;
    }
};