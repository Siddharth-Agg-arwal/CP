int solve(vector<vector<int>>& dp, vector<int> &val, vector<int> &wt, int idx, int W){
	if(idx<0 || W==0) return 0;
	if(dp[idx][W]!=-1) return dp[idx][W];
	int noTake=solve(dp, val, wt, idx-1, W);
	int take=0;
	if(wt[idx]<=W) take = val[idx]+solve(dp, val, wt, idx-1, W-wt[idx]);
	return dp[idx][W]=max(take, noTake);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>>dp(n, vector<int>(w+1, -1));
	return solve(dp, values, weights, n-1, w);
}
