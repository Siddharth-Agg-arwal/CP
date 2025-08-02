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

        unordered_map<int, int> freq_arr;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            freq_arr[nums[i]]++;
            // if (nums[i] == 0)
            //     count0++;
            // else if (nums[i] == 1)
            //     count1++;
        }

        long long final_sum = 0;
        int count0 = 0, count1 = 0;
        if (freq_arr.find(0) != freq_arr.end() && freq_arr.find(1) != freq_arr.end())
        {
            count0 = freq_arr[0], count1 = freq_arr[1];
            int val = min(count0, count1);
            final_sum += 2 * val;
            freq_arr[0] -= val;
            freq_arr[1] -= val;
            // cout << final_sum << " ";
        }
        if (freq_arr.find(0) != freq_arr.end() && freq_arr[0] > 0)
        {
            final_sum += freq_arr[0];
            freq_arr[0] = 0;
        }
        // final_sum += 2 * min(count0, count1);
        for (auto it : freq_arr)
        {
            final_sum += it.first * it.second;
        }

        cout << final_sum << endl;
    }

    return 0;
}