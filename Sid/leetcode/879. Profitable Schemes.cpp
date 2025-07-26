class Solution
{
public:
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int profitableHelper(vector<int> &curr_comb, int curr_people, int curr_idx, int curr_profit, const int &n, const vector<int> &group, const vector<int> &profit, int &ans, const int &minProfit, vector<vector<vector<int>>> &dp)
    {

        if (curr_idx == group.size())
            return (curr_profit >= minProfit) ? 1 : 0;
        if (dp[curr_idx][curr_people][curr_profit] != -1)
            return dp[curr_idx][curr_people][curr_profit];

        int take = 0;
        if (group[curr_idx] + curr_people <= n)
        {
            int next_profit = min(minProfit, curr_profit + profit[curr_idx]);
            take = profitableHelper(curr_comb, curr_people + group[curr_idx], curr_idx + 1, next_profit, n, group, profit, ans, minProfit, dp);
        }

        int not_take = profitableHelper(curr_comb, curr_people, curr_idx + 1, curr_profit, n, group, profit, ans, minProfit, dp);

        return dp[curr_idx][curr_people][curr_profit] = (take + not_take) % MOD;
    }

    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        int ans = 0;
        vector<int> curr_comb;
        // set<vector<int>> combs;
        int curr_people = 0, curr_idx = 0, curr_profit = 0;
        // long long max_prof = 0;
        // for(auto prof : profit) max_prof += prof;
        dp.assign(group.size() + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));
        return profitableHelper(curr_comb, curr_people, curr_idx, curr_profit, n, group, profit, ans, minProfit, dp);
    }
};