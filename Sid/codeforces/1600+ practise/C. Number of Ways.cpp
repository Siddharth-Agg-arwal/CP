// tle

#include <bits/stdc++.h>
using namespace std;

long long helper(int parts, int curr_idx, int n, vector<int> &nums, int target, vector<vector<long long>> &memo)
{

    // if(curr_idx < n){
    //     curr_sum += nums[curr_idx];
    // }
    // cout << nums[curr_idx] << " " << parts <<  endl;
    if (parts == 2)
    {
        if (curr_idx < n)
        {
            return 1;
        }
        return 0;
    }
    if (curr_idx >= n)
        return 0;

    if (memo[curr_idx][parts] != -1)
    {
        return memo[curr_idx][parts];
    }
    // int ans= 0;
    long long ways = 0;
    long long curr_sum = 0;
    for (int i = curr_idx; i < n; i++)
    {
        curr_sum += nums[i];
        if (curr_sum == target)
        {
            ways += helper(parts + 1, i + 1, n, nums, target, memo);
        }
    }

    return memo[curr_idx][parts] = ways;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    if (sum % 3 != 0)
    {
        cout << 0 << endl;
        return 0;
        // continue;
    }
    vector<vector<long long>> memo(n, vector<long long>(3, -1));
    // int ways = 0;
    int target = sum / 3;
    long long ways = helper(0, 0, n, arr, target, memo);
    cout << ways << endl;
}