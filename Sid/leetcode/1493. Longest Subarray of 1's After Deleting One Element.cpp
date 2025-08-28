class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        // int last_zero_idx = -1;
        bool zero_e = false;
        int max_len = 0, prev_ones = 0, curr_ones = 0;
        int n = nums.size();
        // int len = 0;

        for (int i = 0; i < n; i++)
        {

            if (nums[i] == 1)
            {
                curr_ones += 1;
            }
            else
            {
                // if(zero_e){
                zero_e = true;
                curr_ones -= prev_ones;
                prev_ones = curr_ones;
                // len += 1;
                // }
                // else{
                //     zero_e = true;
                // last_zero_idx = i;
                // len += 1;
                // }
            }

            // cout << curr_ones << " " << i << endl;
            max_len = max(max_len, curr_ones);
            if (curr_ones < 0)
            {
                curr_ones = 0;
            }
        }

        return (zero_e == false ? max_len - 1 : max_len);
    }
};