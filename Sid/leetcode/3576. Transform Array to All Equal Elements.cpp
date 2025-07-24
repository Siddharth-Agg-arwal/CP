class Solution
{
public:
    bool canMatch(vector<int> nums, int k, int target)
    {
        for (int i = 0; i < nums.size() - 1 && k >= 0; i++)
        {
            if (nums[i] != target)
            {
                nums[i] = -nums[i];
                nums[i + 1] = -nums[i + 1];
                k -= 1;
            }
        }

        if (k >= 0 && nums[nums.size() - 1] == target)
            return true;
        return false;
    }

    bool canMakeEqual(vector<int> &nums, int k)
    {
        return canMatch(nums, k, -1) || canMatch(nums, k, +1);
    }
};