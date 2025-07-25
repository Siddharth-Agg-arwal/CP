// class segTree{
//     vector<pair<int,int>> seg;
// public:
//     segTree(int n){
//         seg.resize(4 * n + 1);
//     }

//     void build(int idx, int low, int high, vector<int>& nums){
//         if(low == high){
//             seg[idx].first = nums[low];
//             seg[idx].second = nums[low];
//         }
//         int mid = (low + high) / 2;
//         build(2 * idx + 1, low, mid, nums);
//         build(2 * idx + 2, mid + 1, high, nums);

//         seg[idx].first = min(seg[2 * idx + 1].first, seg[2 * idx + 2].first);
//         seg[idx].second = max(seg[2 * idx + 1].second, seg[2 * idx + 2].second);
//     }

//     pair<int,int> query(int idx, int low, int high, int l, int r){
//         if(l > high || r < low) return {INT_MAX, INT_MIN};
//         if(l <= low || r >= high) return seg[idx];

//         int mid = (low + high) / 2;
//         pair<int,int> l_p = query(2 * idx + 1, low, mid, l, r);
//         pair<int,int> r_p = query(2 * idx + 2, mid + 1, high, l, r);

//         seg[idx].first = min(l_p.first, r_p.first);
//         seg[idx].second = max(l_p.first, r_p.second);
//         return seg[idx];
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
//         int m = grid.size();
//         int n = grid[0].size();
//         segTree st(m * n);
//         vector<int> nums;
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 nums.push_back(grid[i][j]);
//             }
//         }
//         vector<vector<int>> ans;
//         st.build(0, 0, m*n, nums);
//         for(int i = 0; i < m-k; i++){
//             vector<int> row;
//             for(int j = 0; j < n-k; j++){
//                 int mins = 1e9;
//                 int maxs = -1e9;
//                 for(int l = 0; l < k; l++){
//                     pair<int,int> min_max = st.query(0, 0, n*m, i + (l*m), j + k + (l*m));
//                     mins = min(min_max.first, mins);
//                     maxs = max(min_max.second, maxs);
//                 }
//                 row.push_back(abs(maxs - mins));
//             }
//             ans.push_back(row);
//         }

//         return ans;
//     }
// };
class Solution
{
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));
        vector<int> window;
        window.reserve(k * k);
        for (int i = 0; i <= m - k; i++)
        {
            for (int j = 0; j <= n - k; j++)
            {
                window.clear();
                for (int di = 0; di < k; di++)
                {
                    for (int dj = 0; dj < k; dj++)
                    {
                        window.push_back(grid[i + di][j + dj]);
                    }
                }
                sort(window.begin(), window.end());
                int best = INT_MAX;
                for (int x = 1; x < (int)window.size(); x++)
                {
                    if (window[x] != window[x - 1])
                    {
                        best = min(best, window[x] - window[x - 1]);
                    }
                }
                ans[i][j] = (best == INT_MAX ? 0 : best);
            }
        }
        return ans;
    }
};
