#include <string.h>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int in(char a, string key, int count)
    {
        for (int i = 0; i < key.length() - count; i++)
        {
            if (a == key[i])
            {

                return i;
                break;
            }
        }
        return -1;
    }

    string decodeMessage(string key, string message)
    {
        char alphabets[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        int count = 0;
        for (int i = 0; i < key.length(); i++)
        {
            if (key[i] == ' ')
            {
                count++;
            }
        }

        key.erase(remove(key.begin(), key.end(), ' '), key.end());
        unordered_map<char, int> exists;
        int index = 0;
        for (int i = 0; i < key.length(); i++)
        {
            if (exists[key[i]] == 0)
            {
                key[index++] = key[i];
                exists[key[i]]++;
            }
        }

        string output = "";
        cout << key << endl;

        for (int i = 0; i < message.length(); i++)
        {
            if (message[i] == ' ')
            {
                output = output + ' ';
            }
            else
            {
                int m = in(message[i], key, count);
                cout << m << endl;
                output = output + alphabets[m];
            }
        }

        return output;
    }
};