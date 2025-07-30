class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int max_el = 0;
        for (int i = 0; i < nums.size(); i++)
            max_el = max(max_el, nums[i]);

        int max_len = 0;
        for (int i = 0; i < nums.size(); i++)
        {

            if (nums[i] == max_el)
            {
                int curr_len = 1;
                int j = i + 1;
                while (j < nums.size() && nums[j] == max_el)
                {
                    curr_len += 1;
                    j += 1;
                }
                i = j;
                max_len = max(max_len, curr_len);
            }
        }

        return max_len;
    }
};