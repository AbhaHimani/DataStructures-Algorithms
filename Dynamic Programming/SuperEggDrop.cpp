// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int dp[201][201];
    int helper(int eggs, int floors)
    {
        if (dp[eggs][floors] != -1)
            return dp[eggs][floors];
        if (floors == 0 || floors == 1)
        {
            dp[eggs][floors] = floors;
            return floors;
        }
        if (eggs == 1)
        {
            dp[eggs][floors] = floors;
            return floors;
        }
        int moves = INT_MAX;
        for (int k = 1; k <= floors; k++)
        {

            int ans = 1 + max(helper(eggs - 1, k - 1), helper(eggs, floors - k));
            moves = min(moves, ans);
        }
        return dp[eggs][floors] = moves;
    }
    int eggDrop(int eggs, int floors)
    {

        memset(dp, -1, sizeof(dp));
        return helper(eggs, floors);
    }
};

// { Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        // calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends