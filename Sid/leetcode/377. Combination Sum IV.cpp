class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<double> combs(target + 1, 0);
        combs[0] = 1;
        for (int i = 1; i < target + 1; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i - nums[j] >= 0)
                    combs[i] += combs[i - nums[j]];
                cout << combs[j]
            }
        }

        return combs[target];
    }
};