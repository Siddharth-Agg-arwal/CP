class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int tot_sum = accumulate(nums.begin(), nums.end(), 0);

        if (tot_sum < abs(target) || (target + tot_sum) % 2 != 0)
            return 0;

        int subset_sum = (target + tot_sum) / 2;

        vector<int> dp(subset_sum + 1, 0);
        dp[0] = 1;

        for (int num : nums)
        {
            for (int j = subset_sum; j >= num; j--)
            {
                dp[j] += dp[j - num];
            }
        }

        return dp[subset_sum];
    }
};
