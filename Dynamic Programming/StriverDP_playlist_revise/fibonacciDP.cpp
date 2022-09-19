// Through Memoization- Top Down Approach
#include <iostream>
#include <vector>
using namespace std;

int f(int n, vector<int> &dp)
{
    if (n <= 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}

// Time complexity: O(n)
// Space complexity: O(n)

// Bottom Up Approach

int f_tab(int n, vector<int> &dp)
{

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Time complexity: O(n)
// Space complexity: O(n)

// Optimising space

int f_tab1(int n, vector<int> &dp)
{
    int prev = 0;
    int prev1 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curri = prev + prev1;
        prev1 = prev;
        prev = curri;
    }
    return prev;
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n, -1);
    cout << f(n, dp) << endl;
    return 0;
}
