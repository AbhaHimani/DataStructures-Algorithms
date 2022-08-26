// Through Memoization- Top Down Approach
#include <iostream>
#include <vector>
using namespace std;
// Tabulation
int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Recursion
int CountDistWayToClimb(long long n)
{
    if (n <= 1)
    {
        return 1;
    }
    return CountDistWayToClimb(n - 1) + CountDistWayToClimb(n - 2);
}

// Memoization
int CountDistWayToClimb(long long n, vector<int> &dp)
{
    if (n <= 1)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = CountDistWayToClimb(n - 1, dp) + CountDistWayToClimb(n - 2, dp);
}
int main()
{
    int n;
    cin >> n;
    cout << CountDistWayToClimb(n) << endl;
    return 0;
}
