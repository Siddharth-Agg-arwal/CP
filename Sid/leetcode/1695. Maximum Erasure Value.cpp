class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n , 0);
        
        sums[0] = nums[0];
        int last_idx = -1;
        for(int i = 1; i < n; i++){
            sums[i] = sums[i - 1]  + nums[i];
            // cout << nums[i] << " ";
        }

        unordered_map<int,int> val_idx;
        int curr_sum = 0;
        int max_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(val_idx.find(nums[i]) == val_idx.end()){
                val_idx[nums[i]] = i;
                if(last_idx == -1) curr_sum = sums[i];
                else curr_sum = sums[i] - sums[last_idx];
                // cout << curr_sum << " " << sums[i] << " ";
            }
            else{
                last_idx = (val_idx[nums[i]] > last_idx ? val_idx[nums[i]] : last_idx);
                val_idx[nums[i]] = i;
                curr_sum = sums[i] - sums[last_idx];
            }
            // cout << curr_sum << " "; 
            max_sum = max(curr_sum, max_sum);
        } 

        return max_sum;

        // return 0;
    }
};