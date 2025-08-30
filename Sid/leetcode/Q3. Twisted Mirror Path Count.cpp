class Solution
{
public:
    int uniquePaths(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 1e9 + 7;
        vector<vector<int>> paths_d(n, vector<int>(m, 0));
        vector<vector<int>> paths_r(n, vector<int>(m, 0));

        paths_r[0][0] = 1;

        // bool t = false;
        // for(int i = 0; i < n; i++){
        //     if(!t) paths[i][0] = 1;
        //     else grid[i][0] = -1;
        //     if(grid[i][0] == 1) t = true;
        // }

        // t = false;
        // for(int j = 0; j < m; j++){
        //     if(!t) paths[0][j] = 1;
        //     else grid[0][j] = -1;
        //     if(grid[0][j] == 1) t = true;
        // }

        // for(int i=1; i<n; i++){
        //     for(int j=1; j < m; j++){
        //         paths[i][j] = paths[i-1][j] + paths[i][j - 1];
        //         // cout << paths[i][j] << " ";
        //     }
        //     // cout << endl;
        // }
        // int tot_paths = paths[n-1][m-1];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    int tot_paths = (paths_d[i][j] + paths_r[i][j]) % mod;
                    if (i + 1 < n)
                    {
                        paths_d[i + 1][j] = (paths_d[i + 1][j] + tot_paths) % mod;
                    }
                    if (j + 1 < m)
                    {
                        paths_r[i][j + 1] = (paths_r[i][j + 1] + tot_paths) % mod;
                    }
                }
                else
                {
                    if (j + 1 < m)
                    {
                        paths_r[i][j + 1] = (paths_r[i][j + 1] + paths_d[i][j]) % mod;
                    }
                    if (i + 1 < n)
                    {
                        paths_d[i + 1][j] = (paths_d[i + 1][j] + paths_r[i][j]) % mod;
                    }
                }
            }
        }

        return (paths_d[n - 1][m - 1] + paths_r[n - 1][m - 1]) % mod;
    }
};