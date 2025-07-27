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

        int l = 0, r = n - 1;
        bool choose_min = true;
        string ans = "";
        int idx_chosen = 0;
        while (l <= r)
        {
            if (choose_min)
            {
                if (nums[l] < nums[r])
                {
                    // idx_chosen = l;
                    ans += 'L';
                    l += 1;

                    // cout << nums[l] << ' ';
                }
                else
                {
                    // idx_chosen = r;
                    ans += 'R';
                    r -= 1;

                    // cout << nums[r] << ' ';
                }
                choose_min = false;
            }
            else
            {
                if (nums[l] > nums[r])
                {
                    // idx_chosen = l;
                    ans += 'L';
                    l += 1;

                    // cout << nums[l] << ' ';
                }
                else
                {
                    // idx_chosen = r;
                    ans += 'R';
                    r -= 1;
                    // cout << nums[r] << " ";
                }

                choose_min = true;
            }

            // cout << nums[idx_chosen] << " ";
        }

        cout << ans << endl;
    }

    return 0;
}