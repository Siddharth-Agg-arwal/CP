class Solution
{
public:
    void subsetHelper(vector<int> &curr, vector<vector<int>> &ans, vector<bool> &visited, const vector<int> &nums, const int &total_combs)
    {

        // if(curr.size() == nums.size()) return;

        if (ans.size() == total_combs)
            return;
        // if(unique.find(curr) == unique.end()){
        ans.push_back(curr);
        // return;
        // }

        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i])
                continue;
            if (curr.size() == 0)
            {
                curr.push_back(nums[i]);
                visited[i] = true;
                subsetHelper(curr, ans, visited, nums, total_combs);
                visited[i] = false;
                curr.pop_back();
            }
            else if (curr.back() < nums[i])
            {
                curr.push_back(nums[i]);
                visited[i] = true;
                subsetHelper(curr, ans, visited, nums, total_combs);
                visited[i] = false;
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        // set<vector<int>> unique;
        vector<vector<int>> ans;
        vector<int> curr = {};
        vector<bool> visited(nums.size(), 0);
        long long total_combs = pow(2, nums.size());
        subsetHelper(curr, ans, visited, nums, total_combs);
        return ans;
    }
};