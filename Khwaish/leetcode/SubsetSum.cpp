bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto n:nums) sum+=n;
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<int>dp(target+1, false);
        dp[0]=true;
        for(auto n:nums){
            for(int curr=target; curr>=n; curr--){
                dp[curr]=dp[curr]||dp[curr-n];
                if(dp[target]) return true;
            }
        }
        return dp[target];
    }
