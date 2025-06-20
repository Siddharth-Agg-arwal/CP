#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> num_freq;
        priority_queue<pair<int, int>> all_nums;

        for (int i = 0; i < nums.size(); i++)
        {
            num_freq[nums[i]] += 1;
        }

        for (auto it : num_freq)
        {
            pair<int, int> val = {it.second, it.first};
            all_nums.push(val);
        }

        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            pair<int, int> top_val = all_nums.top();
            all_nums.pop();

            ans.push_back(top_val.second);
        }

        return ans;
    }
};