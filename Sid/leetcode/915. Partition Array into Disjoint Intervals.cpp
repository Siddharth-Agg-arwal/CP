class Solution
{
public:
    int partitionDisjoint(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> maxL(n, -1e9), minR(n, 1e9);

        maxL[0] = nums[0];
        minR[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++)
        {
            maxL[i] = max(nums[i], maxL[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            minR[i] = min(minR[i + 1], nums[i]);
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (maxL[i] <= minR[i + 1])
            {
                return i + 1;
            }
        }

        return n;
    }
};