class Solution
{
public:
    vector<int> smallestSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> bit_pos(31, -1);

        for (int i = n - 1; i >= 0; i--)
        {
            int j = i;
            for (int bit = 0; bit < 31; bit++)
            {
                if (!(nums[i] & (1 << bit)))
                {
                    if (bit_pos[bit] != -1)
                    {
                        j = max(j, bit_pos[bit]);
                    }
                }
                else
                {
                    bit_pos[bit] = i;
                }
            }
            ans[i] = j - i + 1;
        }

        return ans;
    }
};