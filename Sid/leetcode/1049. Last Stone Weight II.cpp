class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int n = stones.size();
        int k = 0, min_val = 1e9, max_val = -1e9;
        long long sum = 0;
        for (int i = 0; i < stones.size(); i++)
        {
            min_val = min(min_val, stones[i]);
            max_val = max(max_val, stones[i]);
            sum += stones[i];
        }

        if (max_val == min_val && n % 2 == 0)
            return 0;
        if (max_val == min_val)
            return max_val;

        // cout << sum << endl;
        vector<vector<int>> dp(n + 1, vector<int>((sum / 2) + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            int curr_val = stones[i - 1];
            for (int j = 1; j <= (sum / 2); j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j - curr_val >= 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - curr_val] + curr_val);
            }
        }

        // cout << dp[n][sum/2] << endl;
        return sum - 2 * dp[n][sum / 2];
    }
};