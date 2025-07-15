class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int min_val = 501;
        int max_val = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            min_val = min(min_val, nums[i]);
            max_val = max(max_val, nums[i]);
        }

        int max_diff = max_val - min_val;
        if (max_diff == 0)
            return nums.size();

        int subseq_len = 2;
        for (int i = -max_diff; i <= max_diff; i++)
        {
            int curr_diff = i;
            vector<int> subs_size(nums.size(), 1);
            unordered_map<int, int> val_idx;

            val_idx[nums[0]] = 0;
            int max_len = 2;
            for (int j = 1; j < nums.size(); j++)
            {
                if (val_idx.find(nums[j] - curr_diff) != val_idx.end())
                {
                    subs_size[j] = subs_size[val_idx[nums[j] - curr_diff]] + 1;
                    max_len = max(max_len, subs_size[j]);
                }

                val_idx[nums[j]] = j;
            }

            subseq_len = max(subseq_len, max_len);
        }

        return subseq_len;
    }
};