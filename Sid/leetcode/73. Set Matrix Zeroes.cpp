#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<bool> check_rows(rows, false);
        vector<bool> check_cols(cols, false);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    check_rows[i] = true;
                    check_cols[j] = true;
                }
            }
        }

        for (int i = 0; i < rows; i++)
        {
            if (check_rows[i])
            {
                for (int j = 0; j < cols; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < cols; i++)
        {
            if (check_cols[i])
            {
                for (int j = 0; j < rows; j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }
    }
};