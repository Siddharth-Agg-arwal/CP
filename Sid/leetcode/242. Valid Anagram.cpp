#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> freq_arr(26, 0);

        for (int i = 0; i < s.size(); i++)
        {
            freq_arr[s[i] - 'a'] += 1;
        }

        for (int i = 0; i < t.size(); i++)
        {
            freq_arr[t[i] - 'a'] -= 1;
        }

        for (int i = 0; i < 26; i++)
        {
            if (freq_arr[i] != 0)
            {
                return false;
            }
        }

        return true;
    }
};