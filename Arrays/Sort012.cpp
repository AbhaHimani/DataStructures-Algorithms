// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void sort012(int a[], int n)
    {

        int mid = 0;
        int low = 0;
        int high = n - 1;
        while (mid <= high)
        {
            if (a[mid] == 0)
            {
                swap(a[low], a[mid]);
                low++;
                mid++;
            }
            else if (a[mid] == 1)
            {
                mid++;
            }
            else if (a[mid] == 2)
            {
                swap(a[mid], a[high]);

                high--;
            }
        }

        // 0 0 1 2 2
        // 0 0 2 2 1
        // 0 0 1 2 2

        // code here
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends