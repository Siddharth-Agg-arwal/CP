class Solution
{
public:
    static bool comparator(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }

    int longChainHelper(int i, const vector<vector<int>> &pairs, vector<vector<int>> &dp, int prev_idx)
    {
        if (i == pairs.size())
            return 0;

        if (dp[i][prev_idx + 1] != -1)
            return dp[i][prev_idx + 1];

        int not_taken = longChainHelper(i + 1, pairs, dp, prev_idx);
        int taken = 0;
        if (prev_idx == -1 || pairs[i][0] > pairs[prev_idx][1])
            taken = 1 + longChainHelper(i + 1, pairs, dp, i);

        return dp[i][prev_idx + 1] = max(taken, not_taken);
    }

    int findLongestChain(vector<vector<int>> &pairs)
    {
        if (pairs.size() == 0)
            return 0;
        sort(pairs.begin(), pairs.end(), comparator);

        int n = pairs.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return longChainHelper(0, pairs, dp, -1);
    }
};