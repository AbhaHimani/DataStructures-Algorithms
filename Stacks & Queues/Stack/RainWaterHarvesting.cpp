// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        vector<long long> left(n);
        vector<long long> right(n);
        left[0] = arr[0];

        for (int i = 1; i < n; i++)
        {
            left[i] = std::max<long long int>(left[i - 1], arr[i]);
        }
        right[n - 1] = arr[n - 1];
        for (int j = n - 2; j >= 0; j--)
        {
            right[j] = std::max<long long int>(right[j + 1], arr[j]);
        }

        vector<long long> ans;
        for (int i = 0; i < n - 1; i++)
        {
            ans.push_back(min(left[i], right[i]) - arr[i]);
        }
        long long a = 0;
        for (int k = 0; k < ans.size(); k++)
        {

            a = ans[k] + a;
        }
        return a;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;

        int a[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends