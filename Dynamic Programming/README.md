#### House Robber
##### Pick Not pick Concept

```
for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            int notPick = 0;
            if (i > 1)
            {
                pick += dp[i - 2];
            }
            notPick += dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        
```


# 7 Basic Questions
### 01 Knapsack Problem

#### Recursive Approach
```

  int knapsack(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n - 1] <= W)
    {
        return max((val[n - 1] + knapsack(wt, val, W - val[n - 1], n - 1)), val[n - 1] + knapsack(wt, val, W, n));
    }
    else
    {
        return knapsack(wt, val, W, n - 1);
    }
}


```
#### Memoized Approach

```
int knapsack(int W, int wt[], int val[], int n, vector<vector<int>> &dp)
{
    if (n <= 0 || W == 0)
    {
        return 0;
    }
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    if (wt[n - 1] <= W)
    {
        return dp[n][W] = max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1, dp), knapsack(W, wt, val, n - 1, dp));
    }
    else

    {
        return dp[n][W] = knapsack(W, wt, val, n - 1, dp);
    }
}
```
#### Bottom Up Approach
```
 for (int i = 0; i <= n; i++)
    {
        
        for (int j = 0; j <= W; j++)
        {
            if(i==0|| j==0){
                dp[i][j]=0;
            }

            else if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

```

##### Types of Questions on 01 Knapsack
[416.Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/)  `Medium`

[Count of subset sum with given sum](https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1) `Medium`

[Minimum Subset Sum difference aka Last stone weight](https://leetcode.com/problems/last-stone-weight-ii/)

[Target Sum](https://leetcode.com/problems/target-sum/)
