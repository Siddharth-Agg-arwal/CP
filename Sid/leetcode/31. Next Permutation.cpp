#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        bool possible = false;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                possible = true;
                break;
            }
        }

        if (possible)
        {
            int n = nums.size();
            int edit_idx = 0, swap_idx = 0;
            for (int i = n - 1; i >= 1; i--)
            {
                if (nums[i - 1] < nums[i])
                {
                    edit_idx = i - 1;
                    break;
                }
                // cout << i << " ";
            }
            for (int i = n - 1; i > edit_idx; i--)
            {
                if (nums[i] > nums[edit_idx])
                {
                    swap_idx = i;
                    break;
                }
                // cout << i << " ";
            }

            // cout << edit_idx << " " << swap_idx << endl;
            int temp = nums[edit_idx];
            nums[edit_idx] = nums[swap_idx];
            nums[swap_idx] = temp;

            sort(nums.begin() + edit_idx + 1, nums.end());
        }
        else
        {
            sort(nums.begin(), nums.end());
        }
    }
};