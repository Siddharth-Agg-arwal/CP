class Solution
{
public:
    // static bool comparator(const string& a, const string &b){
    //     int i = 0;
    //     if(a.size() == b.size()){
    //         while(a[i] == b[i]){
    //             i++;
    //         }
    //         return a[i] > b[i];
    //     }
    //     else return a.size() > b.size();
    // }

    string largestNumber(vector<int> &cost, int target)
    {
        vector<string> dp(target + 1, "0");
        dp[0] = "";
        for (int i = 1; i <= target; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (i - cost[j] >= 0)
                {
                    // sort(dp[i - cost[j]].begin(), dp[i-cost[j]].end(), comparator);
                    // for(int k = 0; k < 1 && k < dp[i - cost[j]].size(); k++){
                    //     string curr_string = dp[i-cost[j]][k] + to_string(j + 1);
                    //     dp[i].push_back(curr_string);
                    //     cout << curr_string << " ";
                    // }
                    if (dp[i - cost[j]] != "0")
                    {
                        string new_num = dp[i - cost[j]] + to_string(j + 1);
                        if (new_num.size() > dp[i].size())
                        {
                            dp[i] = new_num;
                        }
                        else if (new_num.length() == dp[i].length())
                        {
                            if (new_num > dp[i])
                            {
                                dp[i] = new_num;
                            }
                        }
                    }
                }
            }
            // cout << endl;
        }

        // if(dp[target].size() == 0) return "0";
        // else{
        //     // for(auto d : dp[target]) cout << d <<" ";
        //     sort(dp[target].begin(), dp[target].end(), comparator);
        // }
        return dp[target];
    }
};