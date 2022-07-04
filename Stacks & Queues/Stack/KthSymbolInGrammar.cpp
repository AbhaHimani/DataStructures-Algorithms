class Solution
{
public:
    int solve(int n, int k)
    {
        if (n == 1 && k == 1)
        {
            return 0;
        }
        int mid = pow(2, n - 1) / 2;
        if (k <= mid)
        {
            return solve(n - 1, k);
        }
        else
        {
            return !solve(n - 1, k - mid);
        }
    }
    int kthGrammar(int n, int k)
    {
        return solve(n, k);
    }
};