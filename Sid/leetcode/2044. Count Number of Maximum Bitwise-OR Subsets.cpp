class Solution
{
public:
    // int subsetHelper(int curr_idx, int curr_or, const int& max_or, vector<int>& nums, int& ans, vector<int>& curr_subset){
    //     if(curr_or == max_or){
    //         ans += 1;
    //         // unique.insert(curr_subset);
    //     }
    //     if(curr_subset.size() == nums.size() || curr_idx == nums.size()) return 0;

    //     int take = 0;
    //     if((curr_or | nums[curr_idx]) <= max_or){
    //         int n = curr_subset.size();
    //         if(n > 0 && curr_idx > curr_subset[n - 1]){
    //             curr_subset.push_back(curr_idx);
    //             take = subsetHelper(curr_idx + 1, curr_or | nums[curr_idx], max_or, nums, ans, curr_subset);
    //             curr_subset.pop_back();
    //         }
    //         else if(n == 0){
    //             curr_subset.push_back(curr_idx);
    //             take = subsetHelper(curr_idx + 1, curr_or | nums[curr_idx], max_or, nums, ans, curr_subset);
    //             curr_subset.pop_back();
    //         }
    //     }

    //     int not_take = subsetHelper(curr_idx + 1, curr_or, max_or, nums, ans, curr_subset);
    //     return take + not_take;
    // }

    void subsetHelper(int idx, int n, int curr_or, const int &max_or, const vector<int> &nums, int &count)
    {
        if (idx == n)
        {
            if (curr_or == max_or)
                count++;
            return;
        }

        subsetHelper(idx + 1, n, curr_or, max_or, nums, count);
        subsetHelper(idx + 1, n, curr_or | nums[idx], max_or, nums, count);
    }

    int countMaxOrSubsets(vector<int> &nums)
    {
        int max_or = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            max_or = max_or | nums[i];
        }

        // vector<int> curr_subset;
        // curr_subset.reserve(nums.size());
        // sort(nums.begin(), nums.end());
        // set<vector<int>> unique;
        int val = 0;
        subsetHelper(0, nums.size(), 0, max_or, nums, val);
        // subsetHelper(0, 0, max_or, nums, val, curr_subset);
        return val;
    }
};