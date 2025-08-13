class Solution
{
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>> &grid, int x, int y, int k)
    {
        int tot_rows = grid.size();
        int tot_cols = grid[0].size();

        // int change_r = tot_rows - x;
        // int change_c = tot_cols - y;
        if (k <= 1)
            return grid;

        int top_x = x, top_y = y, bottom_x = (x + k > tot_rows - 1 ? tot_rows - 1 : x + k - 1), bottom_y = (y + k >= tot_cols ? tot_cols : y + k);

        while (top_x < bottom_x)
        {
            for (int i = top_y; i < bottom_y; i++)
            {
                swap(grid[top_x][i], grid[bottom_x][i]);
            }
            top_x += 1;
            bottom_x -= 1;
        }

        return grid;
    }
};