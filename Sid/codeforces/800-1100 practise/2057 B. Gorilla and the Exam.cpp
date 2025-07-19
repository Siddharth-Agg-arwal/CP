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
        // unordered_map<int, int> freq_map;
        // long long max_term = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            // if (max_term < nums[i])
            //     max_term = nums[i];
            // freq_map[nums[i]] += 1;
        }

        sort(nums.begin(), nums.end());

        if (k >= n - 1)
        {
            cout << 1 << endl;
            continue;
        }

        // vector<int> num_freq(max_term + 1, 0);
        // for (int i = 0; i < n; i++)
        // {
        //     // cin >> nums[i];
        //     freq_map[nums[i]] += 1;
        //     // cout << num_freq[nums[i]] << " ";
        // }

        vector<int> num_freq = {1};
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
            {
                num_freq.back()++;
            }
            else
            {
                num_freq.push_back(1);
            }
        }
        sort(num_freq.begin(), num_freq.end());
        bool done = false;
        long long tot_ops = num_freq.size();
        for (int i = 0; i < num_freq.size(); i++)
        {
            if (num_freq[i] == 0)
                continue;
            else
            {
                k -= num_freq[i];
                if (k == 0)
                {
                    cout << tot_ops - 1 << endl;
                    done = true;
                    break;
                }
                else if (k < 0)
                {
                    cout << tot_ops << endl;
                    done = true;
                    break;
                }
                tot_ops -= 1;
            }
        }

        if (!done)
            cout << tot_ops << endl;

        // bool done = false;
        // for (int i = 0; i < max_term + 1; i++)
        // {
        //     if (num_freq[i] == 0)
        //         continue;
        //     else
        //     {
        //         k -= num_freq[i];
        //         if (k == 0)
        //         {
        //             cout << max_term - i << endl;
        //             done = true;
        //             break;
        //         }
        //         else if (k < 0)
        //         {
        //             cout << max_term - i + 1 << endl;
        //             done = true;
        //             break;
        //         }
        //     }
        // }

        // if (!done)
        //     cout << 1 << endl;

        // if (k == 0)
        // {
        //     cout << freq_map.size() << endl;
        //     continue;
        // }

        // priority_queue<int, vector<int>, greater<>> minpq;
        // for (auto it : freq_map)
        // {
        //     minpq.push(it.second);
        // }

        // int tot_ops = freq_map.size();
        // if (minpq.size() == 1)
        // {
        //     cout << 1 << endl;
        //     continue;
        // }
        // else
        // {
        //     while (!minpq.empty() && k > 0)
        //     {
        //         if (minpq.top() <= k)
        //         {
        //             tot_ops -= 1;
        //             k -= minpq.top();
        //             minpq.pop();
        //         }
        //         else
        //         {
        //             break;
        //         }
        //     }
        // }

        // cout
        //     << (tot_ops <= 0 ? 1 : tot_ops) << endl;
    }

    return 0;
}