int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>>dp(n, vector<int>(n, INT_MAX));
        for(int i=0; i<n; i++) dp[i][i]=0;
        for(int l=2; l<n; l++){
            for(int i=1; i<n-l+1; i++){
                int j=i+l-1;
                for(int k=i; k<j; k++){
                    int temp= dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
                    dp[i][j]=min(dp[i][j], temp);
                }
            }
        }
        return dp[1][n-1];
    }
