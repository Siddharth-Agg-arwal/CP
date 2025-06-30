// #define IOS()                    \
//     ios::sync_with_stdio(false); \
//     cin.tie(nullptr);

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        // IOS();
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> rotten;
        int time = 0;
        int fresh_oranges = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 2)
                {
                    rotten.push({i, j});
                }
                else if (grid[i][j] == 1)
                    fresh_oranges += 1;
            }
        }

        if (fresh_oranges == 0)
            return 0;
        static const int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!rotten.empty() && fresh_oranges >= 0)
        {
            queue<vector<int>> rotten_temp;
            int k = rotten.size();
            if (fresh_oranges <= 0)
                return time;
            time += 1;

            while (k > 0)
            {
                pair<int, int> xy = rotten.front();
                rotten.pop();
                k -= 1;

                int x = xy.first;
                int y = xy.second;

                for (auto direction : directions)
                {
                    int dx = x + direction[0];
                    int dy = y + direction[1];

                    if (dx > rows - 1 || dy > cols - 1 || dy < 0 || dx < 0 || grid[dx][dy] != 1)
                        continue;

                    fresh_oranges -= 1;
                    grid[dx][dy] = 2;
                    rotten.push({dx, dy});
                }
            }
        }

        return -1;
    }
};