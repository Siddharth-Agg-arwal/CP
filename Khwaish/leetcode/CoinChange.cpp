int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, -1);
        dp[0]=0;
        for(int amt=1; amt<=amount; amt++){
            int mini=INT_MAX;
            for(auto c:coins){
                if(amt-c>=0){
                    int temp=dp[amt-c];
                    if(temp!=INT_MAX) {
                        int t=temp+1;
                        mini=min(mini, t);
                    }
                }
            }
            dp[amt]=mini;
        }
        return (dp[amount]!=INT_MAX)? dp[amount]:-1;
    }
