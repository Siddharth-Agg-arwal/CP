#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> arr(n);
        // vector<bool> freq_(101, false);
        unordered_set<int> nums;
        int temp_c = c;
        int min_val = 1e9;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            min_val = min(min_val, arr[i]);
            nums.insert(arr[i]);
            // freq_[arr[i]] = true;
        }

        // sort(arr.begin(), arr.end());
        // cout << arr[0] << " ";
        if (c > min_val && nums.find(c) == nums.end())
        {
            cout << 0 << endl;
            continue;
        }
        else
        {
            // cout << "yes" << " ";
            while (1)
            {
                if (nums.count(temp_c) == 0 && temp_c > min_val)
                {
                    break;
                }
                temp_c += 1;
            }
        }

        cout << temp_c - c << endl;
    }

    return 0;
}
