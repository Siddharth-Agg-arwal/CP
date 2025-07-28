class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.length(), m = str2.length();
        vector<vector<int>> lcs(n + 1, vector<int>(m + 1, 0));
        vector<int> overlap_1, overlap_2;
        overlap_1.reserve(m);
        overlap_2.reserve(m);

        int prev_val = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                    // if(lcs[i][j] > prev_val){
                    //     prev_val++;
                    //     overlap_1.push_back(j-1);
                    //     overlap_2.push_back(i-1);
                    //     // cout << j - 1 << " " << i - 1 << endl;
                    // }
                }
                else
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }

        string ans = "";
        int i = n, j = m;
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                ans += str1[i - 1];
                i--;
                j--;
            }
            else
            {
                if (lcs[i - 1][j] > lcs[i][j - 1])
                {
                    ans += str1[i - 1];
                    i--;
                }
                else
                {
                    ans += str2[j - 1];
                    j--;
                }
            }
        }

        while (i > 0)
        {
            ans += str1[i - 1];
            i--;
        }
        while (j > 0)
        {
            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        // cout << ans << endl;

        // string ans = "";
        // // int j = 0;
        // int s1_prev = 0, s2_prev = 0;
        // for(int i = 0; i < overlap_1.size(); i++){
        //     for(int j = s2_prev; j < overlap_1[i]; j++){
        //         ans += str2[j];
        //     }
        //     s2_prev = overlap_1[i] + 1;
        //     int j = s1_prev;
        //     for(; j < overlap_2[i]; j++){
        //         ans += str1[j];
        //     }
        //     s1_prev = overlap_2[i] + 1;
        //     ans += str1[j];
        // }

        // int k = overlap_1.size();
        // for(int i = overlap_1[k-1] + 1; i < m; i++){
        //     ans += str2[i];
        // }
        // for(int i = overlap_2[k-1] + 1; i < n; i++){
        //     ans += str1[i];
        // }

        // cout << ans << endl;

        // for(int i = n; i > 0; i--){
        //     for(int j = m; j > 0; j--){
        //         if(lcs[i][j-1] == lcs[i][j]) continue;
        //         if(lcs[i-1][j-1] < lcs[i][j]){
        //             cout << i << " " << j << endl;
        //             break;
        //         }
        //     }
        // }

        return ans;
    }
};