class Solution
{
public:
    int MAH(vector<int> arr)
    {
        int n = arr.size();
        vector<long long> nsl;
        long long pi = -1;
        stack<pair<long long, long long>> s1;
        for (long long i = 0; i < n; i++)
        {
            if (s1.empty())
            {
                nsl.push_back(pi);
            }
            else if (!s1.empty() && arr[i] <= s1.top().first)
            {
                while (!s1.empty() && arr[i] <= s1.top().first)
                {
                    s1.pop();
                }
                if (s1.empty())
                {
                    nsl.push_back(pi);
                }
                else
                {
                    nsl.push_back(s1.top().second);
                }
            }
            else if (!s1.empty() && arr[i] > s1.top().first)
            {
                nsl.push_back(s1.top().second);
            }
            s1.push({arr[i], i});
        }
        vector<long long> nsr;
        stack<pair<long long, long long>> s2;
        long long pi1 = n;

        for (long long i = n - 1; i >= 0; i--)
        {
            if (s2.empty())
            {
                nsr.push_back(pi1);
            }
            else if (!s2.empty() && s2.top().first >= arr[i])
            {
                while (!s2.empty() && s2.top().first >= arr[i])
                {
                    s2.pop();
                }
                if (s2.empty())
                {
                    nsr.push_back(pi1);
                }
                else
                {
                    nsr.push_back(s2.top().second);
                }
            }
            else if (!s2.empty() && s2.top().first < arr[i])
            {
                nsr.push_back(s2.top().second);
            }
            s2.push({arr[i], i});
        }
        reverse(nsr.begin(), nsr.end());

        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            nsr[i] = nsr[i] - nsl[i] - 1;
            nsr[i] *= arr[i];
            if (nsr[i] > mx)
            {
                mx = nsr[i];
            }
        }
        return mx;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        vector<int> v(matrix[0].size(), 0); // v(m,0);
                                            // 1
        int mx = -999999;
        for (int i = 0; i < (matrix.size()); i++)
        {

            for (int j = 0; j < (matrix[0].size()); j++)
            {
                if (matrix[i][j] == '0')
                {
                    v[j] = 0;
                }
                else if (matrix[i][j] == '1')
                {

                    v[j] = v[j] + 1;
                }
            }

            if (MAH(v) > mx)
            {
                mx = MAH(v);
            }
        }
        return mx;
    }
};