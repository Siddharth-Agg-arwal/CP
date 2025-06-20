#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int str_len = s.size();
        vector<vector<bool>> pal_grid(str_len, vector<bool>(str_len, false));
        for (int i = 0; i < str_len; i++)
        {
            pal_grid[i][i] = true;
        }

        vector<int> ans(2, 0);
        for (int i = 0; i < str_len - 1; i++)
        {
            if (s[i + 1] == s[i])
            {
                pal_grid[i][i + 1] = true;
                ans = {i, i + 1};
            }
        }

        // int k = 2;
        for (int k = 2; k < str_len; k++)
        {
            for (int i = 0; i < str_len - k; i++)
            {
                int j = i + k;
                if (s[i] == s[j] && pal_grid[i + 1][j - 1])
                {
                    pal_grid[i][j] = true;
                    ans = {i, j};
                }
            }
        }

        int i = ans[0];
        int j = ans[1];

        return s.substr(i, j - i + 1);
    }
};