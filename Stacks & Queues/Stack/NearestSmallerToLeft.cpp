
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    void immediateSmaller(int *a, int n)
    {
        vector<int> ans;
        stack<int> s;
        for (int i = n - 1; i >= 0; i--)
        {
            int temp = a[i];

            if (s.empty())
            {
                a[i] = -1;
            }
            else if (!s.empty() && s.top() > a[i])
            {
                while (!s.empty() && s.top() > a[i])
                {
                    s.pop();
                }
                if (s.empty())
                {
                    a[i] = -1;
                }
                else
                {
                    a[i] = s.top();
                }
            }
            else if (!s.empty() && s.top() < a[i])
            {
                a[i] = s.top();
            }
            s.push(temp);
        }
        //  code here
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        ob.immediateSmaller(arr, n);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends