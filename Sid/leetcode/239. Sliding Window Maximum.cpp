#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // priority_queue<int> max_heap;
        // unordered_map<int,int> to_pop;
        vector<int> ans;
        deque<int> max_indices;

        // unordered map - priority queue approach beats 12%
        //  for(int i = 0; i < k; i++){
        //      max_heap.push(nums[i]);
        //  }

        // ans.push_back(max_heap.top());

        // for(int i = k; i < nums.size(); i++){
        //     to_pop[nums[i - k]] += 1;
        //     max_heap.push(nums[i]);
        //     // cout << nums[i-k] << " ";
        //     while(to_pop.find(max_heap.top()) != to_pop.end()){
        //         to_pop[max_heap.top()] -= 1;
        //         if(to_pop[max_heap.top()] == 0){
        //             to_pop.erase(max_heap.top());
        //         }
        //         max_heap.pop();
        //     }
        //     ans.push_back(max_heap.top());
        // }

        // monotonic queue approach beats 90%
        for (int i = 0; i < nums.size(); i++)
        {
            // if(max_indices.empty()){
            //     max_indices.push_back(i);
            //     continue;
            // }

            while (!max_indices.empty() && max_indices.front() <= i - k)
            {
                max_indices.pop_front();
            }

            while (!max_indices.empty() && nums[max_indices.back()] <= nums[i])
            {
                max_indices.pop_back();
            }

            max_indices.push_back(i);

            if (i >= k - 1)
                ans.push_back(nums[max_indices.front()]);
        }

        return ans;
    }
};