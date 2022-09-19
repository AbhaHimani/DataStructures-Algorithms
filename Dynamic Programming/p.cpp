#include <bits/stdc++.h>

using namespace std;

long findKthLargest(vector<int> &arr, int k)
{

    priority_queue<int, vector<int>, greater<int>> minH;
    for (int i = 0; i < arr.size(); i++)
    {
        minH.push(arr[i]);
        if (minH.size() > k)
        {
            minH.pop();
        }
    }
    return minH.top();
}

long getMinimumHealth(vector<int> ini_players, vector<int> new_players, int n)

{

    long result = 0;
    result += findKthLargest(ini_players, n);

    for (int i = 0; i < new_players.size(); i++)
    {
        ini_players.push_back(new_players[i]);
        result += findKthLargest(ini_players, n);
    }
}

int main()
{
}
