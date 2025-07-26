class Solution
{
public:
    pair<int, int> count(string s)
    {
        int z0s = 0;
        int o1s = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                z0s++;
            else
                o1s++;
        }
        return {z0s, o1s};
    }

    int dpHelper(int curr_idx, int curr_m, int curr_n, int m, int n, vector<pair<int, int>> &zero_ones, vector<vector<vector<int>>> &dp)
    {
        if (curr_m > m || curr_n > n)
            return -1e9;
        if (curr_idx == zero_ones.size())
            return 0;
        // if(curr_m <= m || curr_n <= n) return 1;
        if (dp[curr_idx][curr_m][curr_n] != -1)
            return dp[curr_idx][curr_m][curr_n];

        int exclude = dpHelper(curr_idx + 1, curr_m, curr_n, m, n, zero_ones, dp);

        int include = 0;
        auto [z, o] = zero_ones[curr_idx];
        if (curr_m + z <= m && curr_n + o <= n)
        {
            include = 1 + dpHelper(curr_idx + 1, curr_m + z, curr_n + o, m, n, zero_ones, dp);
        }
        dp[curr_idx][curr_m][curr_n] = max(include, exclude);

        return max(include, exclude);
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<pair<int, int>> zero_ones(strs.size());
        for (int i = 0; i < strs.size(); i++)
        {
            zero_ones[i] = count(strs[i]);
        }

        int max_len = 0;
        // for(auto str : strs){
        int curr_max = 0;
        vector dp(strs.size() + 1, vector(m + 1, vector<int>(n + 1, -1)));
        return dpHelper(0, 0, 0, m, n, zero_ones, dp);
    }
};