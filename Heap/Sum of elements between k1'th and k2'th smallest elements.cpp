// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long smallest(long long A[], long long N, long long K)
    {
        priority_queue<long long> maxH;
        for (long long i = 0; i < N; i++)
        {
            maxH.push(A[i]);
            while (maxH.size() > K)
            {
                maxH.pop();
            }
        }
        return maxH.top();
    }
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2)
    {
        long long t = 0;
        long long x1 = smallest(A, N, K1);
        long long x2 = smallest(A, N, K2);
        for (int i = 0; i < N; i++)
        {
            if (A[i] > x1 and A[i] < x2)
            {
                t = t + A[i];
            }
        }
        return t;
        // Your code goes here
    }
};

// { Driver Code Starts.
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n;
        long long a[n + 5];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
    }
    return 0;
}
// } Driver Code Ends