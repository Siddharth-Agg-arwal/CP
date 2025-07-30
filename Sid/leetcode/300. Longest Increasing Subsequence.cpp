class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);

        int max_len = 1;
        for (int i = 0; i < n; i++)
        {
            int curr_max = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                // curr_max = max(curr_max, dp[i]);
            }
            max_len = max(dp[i], max_len);
        }

        return max_len;
    }
};