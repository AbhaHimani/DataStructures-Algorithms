// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to delete middle element of a stack.
    void del(stack<int> &s, int mid)
    {
        if (mid == 0)
        {
            s.pop();
            return;
        }
        int val = s.top();
        s.pop();
        del(s, mid - 1);
        s.push(val);
    }
    void deleteMid(stack<int> &s, int sizeOfStack)
    {
        int mid = ceil((sizeOfStack) / 2);

        del(s, mid);
        // code here..
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int sizeOfStack;
        cin >> sizeOfStack;

        stack<int> myStack;

        for (int i = 0; i < sizeOfStack; i++)
        {
            int x;
            cin >> x;
            myStack.push(x);
        }

        Solution ob;
        ob.deleteMid(myStack, myStack.size());
        while (!myStack.empty())
        {
            cout << myStack.top() << " ";
            myStack.pop();
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends