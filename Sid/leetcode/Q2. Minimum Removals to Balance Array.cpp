class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int max_len = 0;
        for (int i = 0; i < n; i++)
        {
            long long lim = (long long)nums[i] * k;
            auto it = upper_bound(nums.begin() + i, nums.end(), lim);
            int cur_len = distance(nums.begin() + i, it);
            max_len = max(max_len, cur_len);
        }

        return n - max_len;
        // unordered_map<int,int> num_idx;
        // for(int i = 0; i < n; i++){
        //     num_idx[nums[i]] = i;
        // }

        // int minrem = n - 1;
        // for(int i = 0; i < n - 1; i++){
        //     int val = nums[i];
        //     for(int j = k; j > 0; j--){
        //         if(num_idx.find(val * k) != num_idx.end()){
        //             minrem = min(minrem, n - (num_idx[val * k] - i + 1));
        //             break;
        //         }
        //     }
        // }

        // return minrem;
    }
};