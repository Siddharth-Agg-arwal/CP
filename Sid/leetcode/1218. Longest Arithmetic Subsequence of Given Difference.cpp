class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        unordered_map<int, int> val_idx;
        vector<int> subseq_size(arr.size(), 1);
        int max_len = 1;
        val_idx[arr[0]] = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            if (val_idx.find(arr[i] - difference) != val_idx.end())
            {
                subseq_size[i] = subseq_size[val_idx[arr[i] - difference]] + 1;
                max_len = max(max_len, subseq_size[i]);
            }
            val_idx[arr[i]] = i;
        }

        return max_len;
    }
};