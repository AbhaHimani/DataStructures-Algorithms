class Solution
{
public:
    int findKthLargest(vector<int> &arr, int k)
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
};