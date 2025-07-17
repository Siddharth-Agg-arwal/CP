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
        long long n, k;
        cin >> n >> k;
        vector<long long> heights(n);
        for (int i = 0; i < n; i++)
            cin >> heights[i];

        long long start_h = heights[k - 1];
        sort(heights.begin(), heights.end());
        long long max_h = heights[n - 1];
        if (start_h == max_h)
        {
            cout << "YES\n";
            continue;
        }

        int idx = 0;
        for (int i = 0; i < n; i++)
            if (heights[i] == start_h)
            {
                idx = i;
                break;
            }

        long long curr_h = start_h;
        long long time = 0;
        bool possible = true;

        while (curr_h < max_h)
        {
            long long reach = 2 * curr_h - time;
            int j = idx + 1;
            while (j < n && heights[j] <= reach)
                j++;
            if (j == idx + 1)
            {
                possible = false;
                break;
            }
            curr_h = heights[j - 1];
            idx = j - 1;
            time += llabs(curr_h - start_h);
            start_h = curr_h;
            if (time > curr_h - 1)
            {
                possible = false;
                break;
            }
        }

        cout << (possible ? "YES\n" : "NO\n");
    }

    return 0;
}
