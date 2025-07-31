class Solution
{
public:
    int subarrayBitwiseORs(vector<int> &arr)
    {
        // unordered_set<long long> unique_ors;
        // int n = arr.size();
        // vector<vector<long long>> dp(n, vector<long long>(n, 0));

        // for(int i = 0; i < n; i++){
        //     dp[i][i] = arr[i];
        //     unique_ors.insert(arr[i]);
        // }

        // int st_row = 0, st_col = 1;

        // while(st_col < n){
        //     int col_temp = st_col;
        //     for(int i = st_row; col_temp < n; col_temp++, i++){
        //         dp[i][col_temp] = dp[i][col_temp - 1] | dp[i+1][col_temp];
        //         unique_ors.insert(dp[i][col_temp]);
        //     }
        //     st_col += 1;
        // }

        // return unique_ors.size();

        unordered_set<int> total;
        unordered_set<int> curr_ors;

        for (auto a : arr)
        {
            unordered_set<int> next_ors;

            next_ors.insert(a);

            for (auto x : curr_ors)
            {
                next_ors.insert(x | a);
            }

            for (auto y : next_ors)
            {
                total.insert(y);
            }

            curr_ors = next_ors;
        }

        return total.size();
    }
};