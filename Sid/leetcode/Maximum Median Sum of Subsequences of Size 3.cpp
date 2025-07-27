class Solution
{
public:
    long long maximumMedianSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = n - 2;
        long long med_sums = 0;
        while (l < r)
        {
            med_sums += nums[r];
            r -= 2;
            l += 1;
        }

        return med_sums;
    }
};