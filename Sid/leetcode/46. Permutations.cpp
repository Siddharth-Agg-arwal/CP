
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void permuteHelper(int permute_idx, vector<bool> &visited, vector<int> &curr_permute, set<vector<int>> &unique_permutes, vector<vector<int>> &ans, vector<int> &nums)
    {

        if (permute_idx == curr_permute.size())
        {
            if (unique_permutes.find(curr_permute) == unique_permutes.end())
            {
                unique_permutes.insert(curr_permute);
                ans.push_back(curr_permute);
            }
            else
            {
                visited[permute_idx] = false;
                permute_idx -= 1;
            }
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!visited[nums[i] + 10])
            {
                curr_permute[permute_idx] = nums[i];
                visited[nums[i] + 10] = true;
                permuteHelper(permute_idx + 1, visited, curr_permute, unique_permutes, ans, nums);
                visited[nums[i] + 10] = false;
            }
        }

        return;
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        set<vector<int>> unique_permutes;

        int permute_idx = 0;
        vector<int> curr_permute(nums.size(), 0);
        vector<bool> visited(21, false);
        permuteHelper(permute_idx, visited, curr_permute, unique_permutes, ans, nums);

        return ans;
    }
};