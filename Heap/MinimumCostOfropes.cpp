// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        priority_queue<long long, vector<long long>, greater<long long>> minH;
        long long total = 0;
        for (int i = 0; i < n; i++)
        {

            minH.push(arr[i]);
        }
        long long cost = 0;
        while (minH.size() >= 2)
        {
            cost = minH.top();
            minH.pop();
            cost += minH.top();
            minH.pop();
            total = cost + total;
            minH.push(cost);

            cost = 0;
        }
        return total;
    }
};

// { Driver Code Starts.

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends