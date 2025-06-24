// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int tc;
//     cin >> tc;
//     while (tc--)
//     {
//         int n;
//         cin >> n;
//         vector<int> nums(n, 0);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> nums[i];
//         }

//         int min_range = INT_MAX;

//         for (int i = 0; i < n - 1; i++)
//         {
//             bool possible = false;
//             int range = 0, min_val = INT_MAX, max_val = INT_MIN;
//             for (int j = i + 1; j < n; j++)
//             {
//                 min_val = min(min_val, nums[j]);
//                 max_val = max(max_val, nums[j]);

//                 if (nums[i] == min_val || nums[i] == max_val)
//                 {
//                     possible = true;
//                     range = j - i - 1;
//                     break;
//                 }
//                 else if (nums[i] - 1 >= min_val && nums[i] - 1 <= max_val)
//                 {
//                     possible = true;
//                     range = j - i - 1;
//                     break;
//                 }
//                 else if (nums[i] + 1 = min_val && nums[i] + 1 <= max_val)
//                 {
//                     possible = true;
//                     range = j - i - 1;
//                     break;
//                 }
//             }
//             if (possible)
//                 min_range = min(range, min_range);
//         }

//         if (min_range != INT_MAX)
//             cout << min_range << endl;
//         else
//             cout << -1 << endl;
//         // cout << min_range << endl;
//     }

//     return 0;
// }

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    if (n <= 1)
    {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        if (abs(a[i] - a[i + 1]) <= 1)
        {
            cout << 0 << endl;
            return;
        }
    }

    long long min_ops = -1;
    for (int i = 0; i < n; ++i)
    {
        long long current_min = a[i];
        long long current_max = a[i];
        for (int j = i; j < n; ++j)
        {
            current_min = min(current_min, a[j]);
            current_max = max(current_max, a[j]);

            long long ops = j - i;
            bool possible = false;

            if (i > 0)
            {
                long long neighbor = a[i - 1];
                if (max(current_min, neighbor - 1) <= min(current_max, neighbor + 1))
                {
                    possible = true;
                }
            }

            if (j < n - 1)
            {
                long long neighbor = a[j + 1];
                if (max(current_min, neighbor - 1) <= min(current_max, neighbor + 1))
                {
                    possible = true;
                }
            }

            if (possible)
            {
                if (min_ops == -1 || ops < min_ops)
                {
                    min_ops = ops;
                }
            }
        }
    }

    cout << min_ops << endl;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}