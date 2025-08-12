class Solution
{
public:
    int MOD = 1e9 + 7;

    int numWaysHelper(int curr_idx, int curr_sum, int x, int n, int max_factor, vector<vector<int>> &dp, vector<int> &powers)
    {
        if (curr_idx > max_factor + 1)
            return 0;
        if (curr_sum > n)
            return 0;
        if (curr_sum == n)
        {
            // curr_sum = 0;
            // = + 1)%MOD;
            return 1;
        }

        // cout << dp[curr_idx][curr_sum] << " ";
        if (dp[curr_idx][curr_sum] != -1)
        {
            return dp[curr_idx][curr_sum];
        }

        // cout << curr_sum << " ";
        int val = powers[curr_idx], a = 0;
        if (curr_sum + val <= n)
        {
            a = numWaysHelper(curr_idx + 1, curr_sum + val, x, n, max_factor, dp, powers);
        }

        int b = numWaysHelper(curr_idx + 1, curr_sum, x, n, max_factor, dp, powers);
        return dp[curr_idx][curr_sum] = (a + b) % MOD;
    }

    int numberOfWays(int n, int x)
    {
        int max_factor = round(pow(n, 1 / double(x)));
        vector<int> powers(max_factor + 2, 0);
        for (int i = 1; i <= max_factor + 1; i++)
        {
            powers[i] = round(pow(i, x));
        }
        // cout << pow(n, 1/double(x)) << ' ';
        // cout << max_factor << " ";
        vector<vector<int>> dp(max_factor + 2, vector<int>(n + 1, -1));
        // int ans = 0;
        return numWaysHelper(1, 0, x, n, max_factor, dp, powers);
        // return ans;
    }
};