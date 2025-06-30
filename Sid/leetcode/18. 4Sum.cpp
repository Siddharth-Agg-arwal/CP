using ll = long long;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        // set<vector<int>> uniq;
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // if(nums[i] > target) break;
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && nums[j - 1] == nums[j])
                    continue;
                // if(j .nums[i] + nums[j] > target) break;
                int k = j + 1;
                int l = n - 1;

                while (k < l)
                {
                    ll(curr_sum) = ll(nums[i]) + ll(nums[j]) + ll(nums[k]) + ll(nums[l]);
                    // cout << k << " " << l << endl;
                    if (curr_sum > target)
                        l -= 1;
                    else if (curr_sum < target)
                        k += 1;
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        // l -= 1;
                        // k += 1;
                        int vr = nums[l], vl = nums[k];
                        while (k < l && nums[l] == vr)
                            l -= 1;
                        while (k < l && nums[k] == vl)
                            k += 1;
                    }
                }
            }
        }

        return ans;
    }
};