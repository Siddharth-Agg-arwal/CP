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
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        vector<int> maxes(n, 0);
        vector<int> mins(n, 0);

        maxes[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            maxes[i] = max(maxes[i + 1], nums[i]);
        }

        mins[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            mins[i] = min(mins[i - 1], nums[i]);
        }
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (mins[i] == nums[i] || maxes[i] == nums[i])
            {
                ans = ans + '1';
            }
            else
            {
                ans = ans + '0';
            }
        }

        cout << ans << endl;
    }

    return 0;
}
