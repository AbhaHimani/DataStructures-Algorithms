//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    void start(int nums[], int target, vector<int> &res, int n)
    {

        int start = 0;
        int end = n - 1;

        int re = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (target == nums[mid])
            {

                re = mid;
                end = mid - 1;
            }
            else if (target > nums[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        res.push_back(re);
    }
    void end(int nums[], int target, vector<int> &res, int n)
    {

        int start = 0;
        int end = n - 1;

        int re = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (target == nums[mid])
            {
                re = mid;
                start = mid + 1;
            }
            else if (target < nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        res.push_back(re);
    }
    int count(int nums[], int n, int target)
    {
        vector<int> res;
        start(nums, target, res, n);
        end(nums, target, res, n);
        if (res[0] == -1)
            return 0;
        return res[1] - res[0] + 1;
        // code here
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends