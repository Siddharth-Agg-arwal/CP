#include <bits/stdc++.h>
#include <iostream>
#define IOS()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;

// void backtrack(int curr_idx, vector<int> curr_arr, vector<vector<int>>& ans, vector<bool>& visited, const vector<int>& nums, const int & n){

//     if(curr_idx == n && curr_arr.size() == n){
//         ans.push_back(curr_arr);
//         return;
//     }
//     if(curr_idx == n){
//         return;
//     }

//     if(ans.size() == 10){
//         return;
//     }

//     backtrack(curr_idx + 1, curr_arr, ans, visited, nums, n);
//     // int take = 0;
//     for(int i = 0; i < n; i++){
//         if(visited[i]) continue;
//         visited[i] = true;
//         curr_arr.push_back(nums[i]);
//         backtrack(curr_idx + 1, curr_arr, ans, visited, nums, n);
//         curr_arr.pop_back();
//         visited[i] = false;
//     }
// }

int main()
{
    IOS();
    int n;
    cin >> n;
    // n = (n > 10 ?  10 : n);
    vector<int> nums(n);
    // vector<bool> visited(n, false);
    for (int i = 1; i <= n; i++)
    {
        nums[i - 1] = i;
    }
    int total = 1;
    for (int i = 2; i <= n; i++)
    {
        total *= i;
        if (total > 10)
        {
            total = 10;
            break;
        }
    }
    // vector<vector<int>> ans;
    // ans.reserve(10);
    // vector<int> curr_arr;
    // curr_arr.reserve(n);
    // backtrack(0, curr_arr, ans, visited, nums, n);
    // cout << ans.size() << endl;
    // for(int i = 0; i < ans.size(); i++){
    //     for(int j = 0; j < ans[i].size(); j++){
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << total << endl;
    int printed = 0;
    do
    {
        for (int x : nums)
        {
            cout << x << " ";
        }
        cout << endl;

        printed += 1;
        if (printed == 9 || printed == total - 1)
            break;
    } while (next_permutation(nums.begin(), nums.end()));

    if (printed < 10 && n > 1 && printed < total)
    {
        for (int i = n; i >= 1; i--)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}