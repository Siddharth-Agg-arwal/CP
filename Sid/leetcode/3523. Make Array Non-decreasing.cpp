class Solution
{
public:
    int maximumPossibleSize(vector<int> &nums)
    {
        int max_s = 1;
        int prev_v = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] >= prev_v)
            {
                max_s += 1;
                prev_v = nums[i];
            }
        }

        return max_s;
    }
};