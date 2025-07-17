class Solution
{
public:
    int minInsertions(string s)
    {
        // int n = s.size();
        // string str1 = "", str2 = "";
        // if(n%2){
        //     str1 = s.substr(0, (n/2) + 1);
        //     str2 = s.substr((n/2) + 1);
        // }
        // else{
        //     str1 = s.substr(0,(n/2));
        //     str2 = s.substr((n/2));
        // }

        // reverse(str2.begin(), str2.end());
        // cout << str1 << " " << str2;
        // // return 0;
        // vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
        // for(int i = 1; i < str1.size() + 1; i++){
        //     for(int j = 1; j < str2.size() + 1; j++){
        //         if(str1[i - 1] == str2[j  -1]){
        //             dp[i][j] = dp[i-1][j-1] + 1;
        //         }
        //         else{
        //             dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        //         }
        //     }
        // }

        //  int lcs = dp[str1.size()][str2.size()];
        // if (n % 2 == 0)
        //     return 2 * ((n/2)     - lcs);
        // else
        //     return 2 * ((n/2 + 1) - lcs);

        // // if(n%2 == 0) return  2 * ((n/2) - dp[n/2][n/2]) - 1;
        // // return 2 * ((n/2) - dp[n/2][n/2]);
        int n = s.size();
        string str1 = s;
        string str2 = s;
        reverse(str2.begin(), str2.end());

        int m = n;
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        int lcs = dp[m][m];
        return n - lcs;
    }
};