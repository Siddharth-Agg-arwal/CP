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
        // long long n, k, x;
        // cin >> n >> k >> x;
        // vector<long long> nums(n);
        // long long a_sum = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     cin >> nums[i];
        //     a_sum += nums[i];
        // }

        // long long lptr = 0;
        // long long rptr = k;
        // while (lptr < rptr)
        // {
        //     long long mptr = (lptr + rptr) / 2;
        //     if (mptr * a_sum <= x)
        //     {
        //         lptr = mptr + 1;
        //     }
        //     else
        //     {
        //         rptr = mptr;
        //     }
        // }

        // int curr_k = lptr;
        // if (curr_k * a_sum < x)
        // {
        //     cout << 0 << endl;
        //     continue;
        // }
        // // cout << curr_k << " : ";
        // int idx = 0;
        // long long curr_val = (curr_k - 1) * a_sum;
        // for (int i = 0; i < n; i++)
        // {
        //     curr_val += nums[i];
        //     if (curr_val >= x)
        //     {
        //         idx = i;
        //         break;
        //     }
        // }

        // // cout << " : " << idx << " : ";
        // cout << (n - idx) + ((k - curr_k) * n) << endl;

        long long n, k, x;
        cin >> n >> k >> x;
        vector<long long> nums(n);
        long long a_sum = 0;
        vector<long long> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            a_sum += nums[i];
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }

        if (x <= 0)
        {
            if (a_sum <= 0 && x > 0)
            {
                cout << 0 << endl;
                continue;
            }
        }

        long long total_sum = k * a_sum;
        if (total_sum < x)
        {
            cout << 0 << endl;
            continue;
        }

        // Binary search for the first valid index
        long long low = 0, high = k * n, ans_idx = k * n;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long num_blocks = mid / n;
            long long rem_idx = mid % n;

            long long current_sum = num_blocks * a_sum;
            if (rem_idx > 0)
            {
                current_sum += prefix_sum[rem_idx];
            }

            if (current_sum >= x)
            {
                ans_idx = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << (k * n) - ans_idx << endl;
    }

    return 0;
}