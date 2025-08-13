class Solution
{
public:
    int sortPermutation(vector<int> &nums)
    {
        int bit_and = 11111111;
        for (int i = 0; i < nums.size(); i++)
        {
            // if(bit_and == )
            if (nums[i] != i)
            {
                if (bit_and == 11111111)
                {
                    bit_and = i;
                }
                else
                {
                    bit_and = bit_and & i;
                }
            }
        }

        return (bit_and == 11111111 ? 0 : bit_and);
    }
};