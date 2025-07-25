class Solution
{
public:
    bool partitionHelper(long long curr_prod, int curr_idx, vector<bool> &visited, long long target, vector<int> &nums)
    {
        // cout << curr_prod << " ";

        if (curr_prod == target)
            return true;
        if (curr_idx > nums.size() - 1)
            return false;
        if (curr_prod > target)
        {
            // curr_idx -= 1;
            return false;
        }

        visited[curr_idx] = true;
        if (partitionHelper(curr_prod * nums[curr_idx], curr_idx + 1, visited, target, nums))
        {
            return true;
        }
        visited[curr_idx] = false;

        if (partitionHelper(curr_prod, curr_idx + 1, visited, target, nums))
            return true;

        return false;
    }
    bool checkEqualPartitions(vector<int> &nums, long long target)
    {
        // unordered_set<int> uniq;
        vector<bool> visited(nums.size(), false);
        visited[0] = true;
        bool ans = partitionHelper(nums[0], 1, visited, target, nums);
        // cout << ans;
        if (ans)
        {
            long long prod2 = 1;
            for (int i = 0; i < nums.size(); i++)
            {
                if (visited[i])
                    continue;
                prod2 *= nums[i];
            }
            if (prod2 == target)
                return true;
        }
        return false;
    }
};