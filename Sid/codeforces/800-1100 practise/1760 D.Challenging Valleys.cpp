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
        long long n;
        cin >> n;
        vector<long long> nums(n, 0);
        long long min_idx = 1e9 + 7;
        long long min_val = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            if (nums[i] < min_val)
            {
                min_val = nums[i];
                min_idx = i;
            }
            //       cout
            //   << nums[i] << " ";
        }

        // cout << min_idx << endl;

        if (n == 1)
        {
            cout << "YES\n";
            continue;
        }
        bool asc_sorted = true;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                asc_sorted = false;
            }
        }

        if (asc_sorted)
        {
            cout << "YES\n";
            continue;
        }

        bool dsc_sorted = true;
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] < nums[i])
            {
                dsc_sorted = false;
            }
        }

        if (dsc_sorted)
        {
            cout << "YES\n";
            continue;
        }

        bool valley = true;

        int lptr = min_idx;
        int rptr = min_idx;

        while (1)
        {
            if (lptr == 0 && rptr == n - 1)
                break;
            if (lptr > 0)
                lptr -= 1;

            if (rptr < n - 1)
                rptr += 1;

            if (nums[lptr] < min_val || nums[lptr] < nums[lptr + 1])
            {
                valley = false;
                break;
            }
            if (nums[rptr] < min_val || nums[rptr] < nums[rptr - 1])
            {
                valley = false;
                break;
            }
        }

        if (valley)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

// output
// NO
// YES
// NO
// NO
// NO
// YES

// YES
// YES
// NO
// NO
// YES
// YES