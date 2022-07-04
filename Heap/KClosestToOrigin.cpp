class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {

        priority_queue<pair<int, pair<int, int>>> maxH;
        pair<int, pair<int, int>> x;
        for (int i = 0; i < points.size(); i++)
        {
            x.first = pow(points[i][0], 2) + pow(points[i][1], 2);
            x.second.first = points[i][0];
            x.second.second = points[i][1];
            maxH.push(x);

            if (maxH.size() > k)
            {
                maxH.pop();
            }
        }
        vector<int> a;
        vector<vector<int>> ans;
        while (!maxH.empty())
        {
            int x = maxH.top().second.first;
            int y = maxH.top().second.second;
            a.push_back(x);
            a.push_back(y);
            ans.push_back(a);
            a.clear();
            maxH.pop();
        }
        return ans;
    }
};