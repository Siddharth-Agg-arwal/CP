class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        // int min_distance = 1e9;
        // priority_queue<vector<int>, vector<vector<int>>, greater<>> coords_dist;
        queue<tuple<int, int, int>> coords_dist;
        if (grid[0][0] == 1)
            return -1;
        grid[0][0] = 1;
        coords_dist.push({1, 0, 0});
        int directions[8][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

        while (!coords_dist.empty())
        {
            auto [dist, x, y] = coords_dist.front();
            // int dist = top[0];
            // int x = top[1];
            // int y = top[2];
            coords_dist.pop();

            // if(grid[x][y] == 1) continue;
            if (x == rows - 1 && y == cols - 1)
            {
                return dist;
            }
            // grid[x][y] = 1;

            for (auto direction : directions)
            {
                int dx = x + direction[0];
                int dy = y + direction[1];

                if (dx >= 0 && dy >= 0 && dx < rows && dy < cols && grid[dx][dy] == 0)
                {
                    grid[dx][dy] = 1;
                    coords_dist.push({dist + 1, dx, dy});
                    // if(dx == rows - 1 && dy == cols - 1) min_distance = min(min_distance, dist + 1);
                }
            }
        }

        return -1;
    }
};