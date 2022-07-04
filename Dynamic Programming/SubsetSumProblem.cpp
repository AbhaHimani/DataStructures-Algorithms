// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        bool subset[arr.size() + 1][sum + 1];
        int n = arr.size();
        for (int j = 1; j < sum + 1; j++)
        {
            subset[0][j] = false;
        }
        for (int i = 0; i < arr.size() + 1; i++)
        {
            subset[i][0] = true;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {

                if (arr[i - 1] > j)
                {
                    subset[i][j] = subset[i - 1][j];
                }
                else if (arr[i - 1] <= j)
                {
                    subset[i][j] = (subset[i - 1][j - arr[i - 1]] || subset[i - 1][j]);
                }
            }
        }
        return subset[n][sum];
        // code here
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0;
}
// } Driver Code Ends