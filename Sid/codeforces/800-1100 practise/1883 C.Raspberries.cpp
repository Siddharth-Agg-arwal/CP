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
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        int min_req = 1e9;

        if (k != 4)
        {
            for (int i = 0; i < n; i++)
            {
                min_req = min(k - (nums[i] % k), min_req);
                if (nums[i] % k == 0)
                {
                    min_req = 0;
                    break;
                }
            }
            cout << min_req << endl;
            continue;
        }
        else
        {
            int count_even = 0;
            bool flag = false;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] % 2 == 0)
                {
                    count_even += 1;
                }
                min_req = min(k - (nums[i] % k), min_req);
                if (nums[i] % 4 == 0)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                cout << 0 << endl;
                continue;
            }
            if (count_even >= 2)
            {
                cout << 0 << endl;
                continue;
            }
            else
            {
                cout << min(min_req, 2 - count_even) << endl;
            }
        }
    }

    return 0;
}