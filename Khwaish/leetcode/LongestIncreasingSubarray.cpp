int solve(vector<int>& nums, vector<vector<int>>& dp, int idx, int n, int preIdx){
        if(idx>=n) return 0;
        if(dp[idx][preIdx+1]!=-1) return dp[idx][preIdx+1];
        int noTake=solve(nums, dp, idx+1, n, preIdx);
        int take=0;
        if(preIdx==-1 || nums[idx]>nums[preIdx]) take = 1+solve(nums, dp, idx+1, n, idx);
        return dp[idx][preIdx+1]=max(take, noTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return solve(nums, dp, 0, n, -1);
    }
