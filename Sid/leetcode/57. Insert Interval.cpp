#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int new_start = newInterval[0];
        int new_end = newInterval[1];
        bool inserted = false;

        for (int i = 0; i < intervals.size(); i++)
        {
            int int_start = intervals[i][0];
            int int_end = intervals[i][1];

            if (new_start < int_start && !inserted)
            {
                ans.push_back({new_start, new_end});
                inserted = true;
            }
            ans.push_back({int_start, int_end});
        }

        if (!inserted)
        {
            ans.push_back({new_start, new_end});
            // return ans;
        }

        vector<vector<int>> final_ans;
        if (ans.empty())
            return final_ans;
        final_ans.push_back(ans[0]);

        for (int i = 1; i < ans.size(); i++)
        {
            auto &last = final_ans.back();
            int curr_start = ans[i][0];
            int curr_end = ans[i][1];

            if (curr_start <= last[1])
            {
                last[1] = max(last[1], curr_end);
            }
            else
            {
                final_ans.push_back({curr_start, curr_end});
            }
        }

        return final_ans;
    }
};