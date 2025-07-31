class Solution
{
public:
    bool canPartitionGrid(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<long long> row_prefix(rows, 0), col_prefix(cols, 0);

        for (int i = 0; i < rows; i++)
        {
            long long curr_row = 0;
            for (int j = 0; j < cols; j++)
            {
                curr_row += grid[i][j];
            }

            if (i == 0)
                row_prefix[i] = curr_row;
            else
                row_prefix[i] = row_prefix[i - 1] + curr_row;
            // cout << row_prefix[i] << " ";
        }

        long long total = row_prefix[rows - 1];
        if (total % 2 == 1)
            return false;

        // cout << endl;
        for (int i = 0; i < cols; i++)
        {
            long long curr_col = 0;
            for (int j = 0; j < rows; j++)
            {
                curr_col += grid[j][i];
            }

            if (i == 0)
                col_prefix[i] = curr_col;
            else
                col_prefix[i] = col_prefix[i - 1] + curr_col;

            // cout << col_prefix[i] << " ";
        }

        for (int i = 0; i < rows; i++)
        {
            if (total - row_prefix[i] == row_prefix[i])
                return true;
        }
        for (int j = 0; j < cols; j++)
        {
            if (total - col_prefix[j] == col_prefix[j])
                return true;
        }

        return false;
    }
};