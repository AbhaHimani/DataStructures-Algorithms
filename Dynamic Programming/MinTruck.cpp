class Solution
{
public:
    static int cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (truckSize - boxTypes[i][0] >= 0)
            {
                truckSize -= boxTypes[i][0];
                ans = ans + boxTypes[i][0] * boxTypes[i][1];
            }
            else
            {
                ans = ans + boxTypes[i][1] * truckSize;
                break;
            }
        }
        return ans;
    }
};