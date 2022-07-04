// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int ans[1001][1001];
    int s(int arr[], int i, int j)
    {
        if (i >= j)
        {
            return 0;
        }
        if (ans[i][j] != -1)
        {
            return ans[i][j];
        }
        int min = INT_MAX;

        for (int k = i; k < j; k++)
        {
            int temp = s(arr, i, k) + s(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
            if (temp < min)
            {
                min = temp;
            }
        }
        return ans[i][j] = min;
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(ans, -1, sizeof(ans));
        return s(arr, 1, N - 1);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
} // } Driver Code Ends