#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubsequence(string s, int k)
    {
        double curr_val = 0;
        int curr_len = s.size();

        bool val_greater = false;
        int j = 0, big_idx = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                curr_val += pow(2, j);
            }
            if (curr_val > k)
            {
                val_greater = true;
                big_idx = i;
                break;
            }
            j += 1;
        }

        if (!val_greater)
            return s.size();

        int numOnes = 0;
        for (int i = 0; i <= big_idx; i++)
        {
            if (s[i] == '1')
                numOnes += 1;
        }

        return s.size() - numOnes;
    }
};