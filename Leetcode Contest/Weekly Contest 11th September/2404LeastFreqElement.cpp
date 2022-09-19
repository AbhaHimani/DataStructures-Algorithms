class Solution
{
public:
    int mostFrequentEven(vector<int> &nums)
    {
        vector<int> n;
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] % 2 == 0)
            {
                mp[nums[i]]++;
            }
        }
        if (mp.empty())
        {
            return -1;
        }

        for (auto i : mp)
        {
            cout << i.first << " ";

            cout << i.second << " ";
            cout << endl;
        }

        int ans;
        int mx = INT_MIN;
        for (auto i : mp)
        {

            if (i.second > mx || (i.first < ans && i.second >= mx))
            {
                mx = i.second;
                cout << mx;
                ans = i.first;
            }
        }
        return ans;
    }
};