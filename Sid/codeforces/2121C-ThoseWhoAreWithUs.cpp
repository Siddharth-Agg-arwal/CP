#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main()
{
    int tests = 0;
    cin >> tests;

    for (int test = 0; test < tests; test++)
    {
        int rows = 0, cols = 0;
        cin >> rows >> cols;
        int max_val = 0;
        vector<vector<int>> grid(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> grid[i][j];
                max_val = max(max_val, grid[i][j]);
            }
        }
    }

    return 0;
}