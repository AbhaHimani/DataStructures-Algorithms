int findSplitPoint(vector<int> skill)
{
    int n = skill.size();
    int leftSum = 0;

    for (int i = 0; i < n; i++)
    {

        leftSum += arr[i];

        int rightSum = 0;
        for (int j = i + 1; j < n; j++)
            rightSum += arr[j];

        if (leftSum == rightSum)
            return i + 1;
    }

    return -1;
}

// Prints two parts after finding split point using
// findSplitPoint()
long printTwoParts(vector<int> skill)
{
    int n = skill.size();
    int splitPoint = findSplitPoint(skill, n);
    int left = 1;
    int right = 1;
    long result = 0;
    if (splitPoint == -1 || splitPoint == n)
    {

        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        if (splitPoint >= i)
        {
            right *= skill[i];
        }
        else
        {
            left *= skill[i];
        }
    }
    return left + right;
}
int main()
{
    vector<int> s = {1, 2, 3, 2};
    printTwoParts(s);
}