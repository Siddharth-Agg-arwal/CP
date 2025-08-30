class Solution
{
public:
    bool checkRows(int row, vector<vector<char>> &board)
    {
        vector<bool> visited(10, false);
        for (int j = 0; j < 9; j++)
        {
            if (board[row][j] == '.')
                continue;
            int val = board[row][j] - '0';
            // cout << val << endl;
            if (!visited[val])
                visited[val] = true;
            else
                return false;
        }

        return true;
    }

    bool checkCols(int col, vector<vector<char>> &board)
    {
        vector<bool> visited(10, false);
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == '.')
                continue;
            int val = board[i][col] - '0';
            // cout << val << endl;
            if (!visited[val])
                visited[val] = true;
            else
                return false;
        }
        return true;
    }

    bool checkCubes(int row, int col, vector<vector<char>> &board)
    {
        vector<bool> visited(10, false);

        for (int i = row; i < 9 && i < 3 + row; i++)
        {
            for (int j = col; j < 9 && j < 3 + col; j++)
            {
                if (board[i][j] == '.')
                    continue;
                int val = board[i][j] - '0';
                // cout << val << endl;
                if (!visited[val])
                    visited[val] = true;
                else
                    return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            if (!checkRows(i, board))
                return false;
            if (!checkCols(i, board))
                return false;
        }

        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                if (!checkCubes(i, j, board))
                    return false;
            }
        }

        return true;
    }
};