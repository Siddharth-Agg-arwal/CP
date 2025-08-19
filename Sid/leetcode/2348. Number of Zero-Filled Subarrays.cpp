class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long ans = 0;
        int w_st = 0;
        int w_end = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                w_st = i;
                w_end = w_st;
                while (i < n && nums[i] == 0)
                {
                    i += 1;
                    w_end += 1;
                }

                ans += ((long long)(w_end - w_st) * (long long)(w_end - w_st + 1)) / 2;
            }

            // i = w_end - 1;
        }

        return ans;
    }
};