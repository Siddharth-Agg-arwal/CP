class Solution
{
public:
    int numSubmat(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> width(n, vector<int>(m, 0));
        // vector<vector<int>> dp_col(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    width[i][j] = (j == 0 ? 1 : width[i][j - 1] + 1);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (mat[i][j] == 1)
                {
                    int w = width[i][j];

                    for (int k = i; k >= 0; k--)
                    {
                        w = min(w, width[k][j]);
                        if (w == 0)
                            break;
                        ans += w;
                    }
                }
            }
        }

        return ans;

        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= m; j++){
        //         if(mat[i-1][j-1] == 1){
        //             dp_row[i][j] = dp_row[i][j-1] + 1;
        //         }
        //     }
        // }

        // for(int i = 1; i <=n ;i++){
        //     for(int j = 1; j <= m; j++){
        //         if(dp_row[i][j] == 1 || dp_col[i][j] == 1){
        //             ans += max(dp_row[i][j], dp_col[i][j]);
        //         }
        //         else{
        //             ans += dp_row[i][j] * dp_col[i][j];
        //         }
        //     }
        // }

        return ans;

        // return ans;
    }
};