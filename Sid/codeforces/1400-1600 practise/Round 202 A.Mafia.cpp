#include <bits/stdc++.h>
#include <iostream>
#define IOS()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;

int main()
{
    IOS();
    int n;
    cin >> n;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    long long max_elem = 0;
    long long want_to_play = 0;
    long long games_can_be_played = 0;
    for (int i = 0; i < n; i++)
    {
        max_elem = max(max_elem, nums[i]);
        sum += nums[i];
    }

    // for (int i = 0; i < n; i++)
    // {
    //     // max_elem = max(max_elem, nums[i]);
    //     games_can_be_played += max_elem - nums[i];
    // }

    cout << max(max_elem, (sum + n - 2) / (n - 1)) << endl;
    return 0;
}