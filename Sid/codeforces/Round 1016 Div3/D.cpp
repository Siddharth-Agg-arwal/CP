#include <bits/stdc++.h>
#include <iostream>
#define IOS()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;

int main()
{
    IOS();
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, q;
        cin >> n >> q;
        long long val = 1;
        long long total_terms = 1;
        while (n--)
            total_terms * 2;

        int box_n = 0,
            offset_x = 0,
            offset_y = 0, it = 1;
        vector<vector<int>> grid(total_terms, vector<int>(total_terms, 0));
        while (val < total_terms + 1)
        {
            grid[box_n + offset_x][box_n + offset_y] = val;
            val += 1;

            grid[box_n + offset_x + 1][box_n + offset_y + 1] = val;
            val += 1;

            grid[box_n + offset_x + 1][box_n + offset_y] = val;
            val += 1;

            grid[box_n + offset_x][box_n + offset_y + 1] = val;
            val += 1;

            box_n += 1;
            if (box_n % 4 == 1)
            {
                offset_x = offset_x + it;
                offset_y = offset_y + it;
            }
            if (box_n % 4 == 2)
            {
                // offset_x = offset_x - it;
                offset_y = offset_y - it;
            }
            if (box_n % 4 == 3)
            {
                offset_x = offset_x - it;
                offset_y = offset_y + it;
            }
            if (box_n % 4 == 0)
            {
                offset_x = offset_x + it;
                offset_y = offset_y + it;
            }
        }
    }

    return 0;
}