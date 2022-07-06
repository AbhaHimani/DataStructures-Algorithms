#include <string.h>
#include <iostream>
using namespace std;
#include <unordered_map>
class Solution
{
public:
    unordered_map<string, bool> mp;
    bool isScramble(string S1, string S2)
    {
        if (S1.length() != S2.length())
        {
            return false;
        }

        int n = S1.length();

        if (n == 0)
        {
            return true;
        }

        if (S1 == S2)
        {
            return true;
        }

        string copy_S1 = S1, copy_S2 = S2;

        sort(copy_S1.begin(), copy_S1.end());
        sort(copy_S2.begin(), copy_S2.end());

        if (copy_S1 != copy_S2)
        {
            return false;
        }

        string key = (S1 + " " + S2);

        if (mp.find(key) != mp.end())
        {
            return mp[key];
        }

        bool flag = false;

        for (int i = 1; i < n; i++)
        {

            if ((isScramble(S1.substr(0, i), S2.substr(0, i)) && isScramble(S1.substr(i, n - i),
                                                                            S2.substr(i, n - i))) ||
                isScramble(S1.substr(0, i), S2.substr(n - i, i)) && isScramble(S1.substr(i, n - i),
                                                                               S2.substr(0, n - i)))
            {
                flag = true;
                return true;
            }
        }

        return mp[key] = flag;
    }
};