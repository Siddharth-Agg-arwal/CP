class Solution
{
public:
    void uniqPermHelper(vector<int> &curr, vector<vector<int>> &ans, vector<bool> &visited, const vector<int> &nums)
    {
        if (curr.size() == nums.size())
        {
            ans.push_back(curr);
            // unique.insert(curr);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i])
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
                continue;
            visited[i] = true;
            curr.push_back(nums[i]);
            uniqPermHelper(curr, ans, visited, nums);
            curr.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<bool> visited(nums.size(), false);
        vector<int> curr;
        set<vector<int>> unique;
        sort(nums.begin(), nums.end());
        // for(int i = 0; i < nums.size(); i++){
        //     if(i > 0 && nums[i] == nums[i-1]) continue;
        //     visited[i] = true;
        //     curr.push_back(nums[i]);
        uniqPermHelper(curr, ans, visited, nums);
        //     curr = {};
        //     visited[i] = false;
        // }

        return ans;
    }
};