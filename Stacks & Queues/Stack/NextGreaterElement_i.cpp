class Solution
{
public:
    int find(int x, vector<int> nums2)
    {
        int ans = -1;
        for (int i = 0; i < nums2.size(); i++)
        {
            if (x == nums2[i])
            {
                ans = i;
            }
        }
        return ans;
    }
    int helper(int x, vector<int> nums2)
    {
        int a = find(x, nums2);
        stack<int> ans;
        if (a == -1)
        {
            return -1;
        }
        else if (a == (nums2.size() - 1))
        {
            return -1;
        }

        else
        {
            for (int i = nums2.size() - 1; i > a; i--)
            {
                ans.push(nums2[i]);
            }

            while (!ans.empty())
            {
                if (ans.top() > x)
                {
                    return ans.top();
                }
                ans.pop();
            }
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> m;
        for (int i = 0; i < nums1.size(); i++)
        {
            m.push_back(helper(nums1[i], nums2));
        }
        return m;
    }
};