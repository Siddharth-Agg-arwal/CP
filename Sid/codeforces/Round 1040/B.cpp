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
        int n, s;
        cin >> n >> s;
        vector<int> nums(n);
        long long sum = 0;
        int count0 = 0, count1 = 0, count2 = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            sum += nums[i];
            if (nums[i] == 0)
                count0++;
            else if (nums[i] == 1)
                count1++;
            else
                count2++;
        }

        if (sum < s)
        {
            long long remainder = s - sum;
            if (remainder > 1)
            {
                cout << -1 << "\n";
            }
            else
            {
                for (int i = 0; i < count0; ++i)
                    cout << "0 ";
                for (int i = 0; i < count2; ++i)
                    cout << "2 ";
                for (int i = 0; i < count1; ++i)
                {
                    cout << "1" << (i == count1 - 1 ? "" : " ");
                }
                cout << "\n";
            }
        }
        else if (sum == s)
        {
            cout << -1 << "\n";
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                cout << nums[i] << (i == n - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }

    return 0;
}