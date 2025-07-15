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

        sort(nums.begin(), nums.end());
        int largest = nums[n - 1];
        // cout << largest;
        // vector<vector<int>> matrix(largest, vector<int>(largest, 0));

        // for (int i = n - 1; i >= 0; i--)
        // {

        // }

        unordered_map<int, int> freq_map;
        for (int i = 0; i < nums.size(); i++)
        {
            freq_map[nums[i]] += 1;
            // cout << i << " : freq = " << freq_map[nums[i]] << endl;
        }

        int prev_freq = freq_map[largest];
        if (freq_map[largest] != nums[0])
        {
            cout << "NO\n";
            continue;
        }

        int j = 1;
        bool possible = true;
        for (int i = largest - 1; i >= 1 && j < nums.size(); i--, j++)
        {
            // cout << i << " : ";
            freq_map[i] += prev_freq;
            // cout << freq_map[i] << endl;
            if (freq_map[i] != nums[j])
            {
                possible = false;
                break;
            }
            prev_freq = freq_map[i];
        }

        if (possible)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}