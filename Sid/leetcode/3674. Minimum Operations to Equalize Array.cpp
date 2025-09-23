class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        bool t = false;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                t = true;
                break;
            }
        }

        if (t)
            return 1;
        return 0;
    }
};