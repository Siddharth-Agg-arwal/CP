#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int str_len = s.size();
        vector<vector<bool>> pal_grid(str_len, vector<bool>(str_len, false));

        int count = 0;
        for (int i = 0; i < str_len; i++)
        {
            pal_grid[i][i] = true;
            count += 1;
        }

        for (int i = 0; i < str_len - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                pal_grid[i][i + 1] = true;
                count += 1;
            }
        }

        for (int k = 2; k < str_len; k++)
        {
            for (int i = 0; i < str_len - k; i++)
            {
                int j = i + k;
                if (s[i] == s[j] && pal_grid[i + 1][j - 1])
                {
                    pal_grid[i][j] = true;
                    count += 1;
                }
            }
        }

        return count;
    }
};