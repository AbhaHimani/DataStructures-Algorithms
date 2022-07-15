long n = A.size();
vector<long> B(n + 1, 0);
for (long i = 0; i < A.size(); i++)
{
    B[A[i]]++;
}
long a, b;
for (long i = 1; i <= A.size(); i++)
{
    if (B[i] == 2)
        a = i;
    if (B[i] == 0)
        b = i;
}
vector<int> result{a, b};
return result;

/////////////////////////////////////////////////

vector<int> Solution::repeatedNumber(const vector<int> &A)
{
    unordered_map<long long, long long> mp;

    for (long long i = 0; i < A.size(); i++)
    {

        mp[A[i]]++;
    }
    vector<int> ans;

    a, b;
    for (auto i : mp)
    {
        if (i.second == 2)
        {
            a = i.first;
        }
    }
    long long sum = 0;
    for (long long i = 0; i < A.size(); i++)
    {
        sum += A[i];
    }
    long long x = 0;
    for (long long i = 1; i <= A.size(); i++)
    {
        x += i;
    }
    b = -sum + a + x;
    ans.push_back(a);
    ans.push_back(b);

    return ans;
}
