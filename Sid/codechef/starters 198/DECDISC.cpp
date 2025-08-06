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
        vector<int> nums(n);

        for (int i = 0; i < n; i++)
            cin >> nums[i];

        int tot_min = 1e9;
        for (int i = 0; i < n - 1; i++)
        {
            int curr_min = 1e9;
            for (int j = i + 1; j < n; j++)
            {
                curr_min = min(curr_min, nums[i] + nums[j]);
            }
            tot_min = min(curr_min, tot_min);
        }

        for (int i = 0; i < n - 1; i++)
        {
            tot_min = min(tot_min, (nums[i] + nums[i + 1] / 2));
        }

        cout << tot_min << endl;
    }

    return 0;
}