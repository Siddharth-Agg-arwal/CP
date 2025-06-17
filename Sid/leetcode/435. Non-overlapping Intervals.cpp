#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static bool comparator(vector<int> &a, vector<int> &b)
    {
        // if(a[0] == b[0]){
        //     return a[1] - a[0] < b[1] - b[0];
        // }
        // else{
        //     return a[0] < b[0];
        // }
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), comparator);
        // int start_min = intervals[0][0];
        int end_max = intervals[0][1];

        // for(auto interval : intervals){
        //     cout << interval[0] << "," << interval[1] << "  ";
        // }
        int removed = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];

            if (curr_start < end_max)
            {
                removed += 1;
            }
            else
            {
                end_max = curr_end;
            }
        }
        return removed;
    }
};