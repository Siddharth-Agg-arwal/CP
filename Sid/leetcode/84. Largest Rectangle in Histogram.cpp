#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        // int max_area = 0;
        // for(int i = 0; i < heights.size(); i++){
        //     if(i > 0 && heights[i] == heights[i-1]) continue;
        //     int start_idx = i - 1;
        //     int end_idx = i + 1;
        //     int curr_area = heights[i];
        //     int curr_height = heights[i];

        //     while(start_idx >= 0){
        //         if(heights[start_idx] < curr_height) break;
        //         curr_area += curr_height;
        //         start_idx -= 1;
        //     }

        //     while(end_idx < heights.size()){
        //         if(heights[end_idx] < curr_height) break;
        //         curr_area += curr_height;
        //         end_idx += 1;
        //     }

        //     max_area = max(curr_area, max_area);

        // }

        // return max_area;

        int max_area = 0;
        stack<int> mo_st;
        for (int i = 0; i <= heights.size(); i++)
        {
            int curr_height = (i == heights.size()) ? 0 : heights[i];
            // int curr_area = 0;

            while (!mo_st.empty() && curr_height < heights[mo_st.top()])
            {
                // int curr_idx = mo_st.top();
                int height = heights[mo_st.top()];
                mo_st.pop();
                int width = mo_st.empty() ? i : i - mo_st.top() - 1;
                int curr_area = height * width;
                max_area = max(curr_area, max_area);
            }

            mo_st.push(i);
        }

        return max_area;
    }
};