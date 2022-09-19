#define MOD 1000000007
public:
int solve(int arr[], int n, int sum)
{
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int j = 0; j < sum + 1; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n + 1; i++)
    {

        for (int j = 0; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]) % MOD;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] % MOD;
            }
        }
    }
    return dp[n][sum];
}
int perfectSum(int arr[], int n, int sum)
{
    return solve(arr, n, sum);

    // Your code goes here
}
