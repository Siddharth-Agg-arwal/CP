#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end());
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> &last = merged.back();
            int curr_start = intervals[i][0], curr_end = intervals[i][1];

            if (curr_start <= last[1])
            {
                last[1] = max(curr_end, last[1]);
            }
            else
            {
                merged.push_back({curr_start, curr_end});
            }
        }

        return merged;
    }
};