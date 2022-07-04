// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // void insert(stack<int>&s,int ele,vector<int>&ans){
    //     if(s.empty()){
    //         s.push(ele);
    //         ans.push_back(ele);
    //         return;
    //     }
    //     int temp=s.top();
    //     s.pop();
    //     insert(s,ele,ans);
    //     s.push(temp);
    //     return;
    // }
    // void Rev(stack<int>&s,vector<int>&ans){
    //   if(s.size()==1){
    //       return;
    //   }
    //   int ele=s.top();
    //   s.pop();
    //   Rev(s,ans);
    //   insert(s,ele,ans);
    //   return ;

    // }
    vector<int> Reverse(stack<int> St)
    {
        vector<int> ans;
        if (St.size() == 0)
        {
            return ans;
        }
        while (!St.empty())
        {
            ans.push_back(St.top());
            St.pop();
        }

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        stack<int> St;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            St.push(x);
        }
        Solution ob;
        vector<int> ans = ob.Reverse(St);
        for (int i = 0; i < N; i++)
        {
            cout << ans[i];
            if (i != N - 1)
                cout << " ";
        }
        cout << endl;
    }
} // } Driver Code Ends