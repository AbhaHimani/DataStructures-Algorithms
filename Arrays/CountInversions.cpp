<<<<<<< HEAD
#include <bits/stdc++.h>
long long getInversions(long long *arr, int n)
{
    long long count = 0;
    vector<vector<long long>> dp[n];
    dp[n] = 0;
    long long count = 0;
    for (long long i = n - 2; i >= 0n; i--)
    {
        if (arr[i] > arr[i + 1])
        {
            dp[i] = min(dp[i - 1], count);
            count = max(count, dp[i]);
        }
    }

    return count;
    // Write your code here.
=======
#include <bits/stdc++.h>
long long getInversions(long long *arr, int n)
{
    long long count = 0;
    vector<vector<long long>> dp[n];
    dp[n] = 0;
    long long count = 0;
    for (long long i = n - 2; i >= 0n; i--)
    {
        if (arr[i] > arr[i + 1])
        {
            dp[i] = min(dp[i - 1], count);
            count = max(count, dp[i]);
        }
    }

    return count;
    // Write your code here.
>>>>>>> eea3f73c4a16a3b3ca27e6fd3def95a51d2f93fe
}