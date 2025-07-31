// class Solution {
// public:
//     int getMoneyAmount(int n) {
//         if(n == 1) return 0;

//         int start = 0, arr_size = 0, end = 0;
//         if(n%2 == 0){
//             start = 1;
//             end = n - 1;
//             arr_size = (n/2);
//             // arr_size2 = n/2;
//         }
//         else{
//             start = 2;
//             end = n - 1;
//             arr_size = (n/2);
//             // arr_size2 =
//         }

//         vector<int> prefix(arr_size), suffix(arr_size), nums(arr_size);
//         // prefix[0] = start;
//         // suffix[arr_size - 1] = end;
//         // int diff = 2;
//         for(int i = start, it = 0; i <= end; i+=2, it += 1){
//             if(it == 0) prefix[it] = i;
//             else prefix[it] = i + prefix[it - 1];
//             // nums[it] = i;
//         }
//         // int j = arr_size - 1;
//         for(int i = end, it = arr_size - 1; i > 0; i -= 2, it -=1){
//             if(it == arr_size - 1) suffix[it] = i;
//             else suffix[it] = suffix[it + 1] + i;
//             // it -= 1;
//         }

//         // cout << prefix.size() << " " << suffix.size();

//         int ans =1e9;
//         // int k = 0;
//         for(int i = 0; i < arr_size; i++){
//             // cout << prefix[i] << " " << suffix[i] << endl;
//             ans = min(ans, max(prefix[i], suffix[i]));
//         }

//         return ans;
//     }
// };

class Solution
{
public:
    int getMoneyAmount(int n)
    {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int len = 2; len <= n; ++len)
        {
            for (int i = 1; i + len - 1 <= n; ++i)
            {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; ++k)
                {
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
                }
            }
        }
        return dp[1][n];
    }
};
