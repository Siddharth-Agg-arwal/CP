// incomplete

#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main()
{
    int tests = 0;
    cin >> tests;

    for (int t = 0; t < tests; t++)
    {
        int rows = 0, cols = 0, exp_size = 0;
        cin >> rows >> cols >> exp_size;
        vector<vector<int>> gold_locations;
        // vector<vector<int>> explosion_locations;
        queue<vector<int>> explosion_locations;
        set<vector<int>> exploded;
        // vector<vector<bool>> exploded(rows, vector<bool>(cols, 0));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                char val = '\0';
                cin >> val;
                if (val == '.')
                {
                    explosion_locations.push({i, j});
                }
                else if (val == 'g')
                {
                    gold_locations.push_back({i, j});
                }
            }
        }

        while (!explosion_locations.empty())
        {
        }
    }
}