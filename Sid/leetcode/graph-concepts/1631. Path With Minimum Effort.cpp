class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> abs_differences(rows, vector<int>(cols, 1e9));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> m_heap;

        m_heap.emplace(0, 0, 0); // x, y, height
        abs_differences[0][0] = 0;
        // vector<vector<pair<int,int>>> coords(rows, vector<pair<int,int>>(cols));
        // vector<vector<bool>> seen(rows, vector<bool>(cols, false));
        // coords[0][0] = {-1,-1};
        int directions[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while (!m_heap.empty())
        {
            auto [effort, x, y] = m_heap.top();
            // int effort = top[0];
            // int x = top[1];
            // int y = top[2];
            // int height = top[2];
            m_heap.pop();

            // if(seen[x][y]) continue;
            // seen[x][y] = true;

            if (effort > abs_differences[x][y])
                continue;

            if (x == rows - 1 && y == cols - 1)
                break;

            for (auto direction : directions)
            {
                int dx = x + direction[0];
                int dy = y + direction[1];

                if (dx >= 0 && dy >= 0 && dx <= rows - 1 && dy <= cols - 1)
                {
                    int new_effort = max(abs(heights[x][y] - heights[dx][dy]), effort);
                    if (new_effort < abs_differences[dx][dy])
                    {
                        // coords[dx][dy] = {x, y};
                        abs_differences[dx][dy] = new_effort;
                        m_heap.emplace(new_effort, dx, dy);
                    }
                }
            }
        }

        // int max_diff = 0;

        // int dx = rows - 1, dy = cols - 1;
        // while(dx >= 0 && dy >= 0){
        //     max_diff = max(max_diff, abs_differences[dx][dy]);
        //     int t_dx = dx, t_dy = dy;
        //     dx = coords[t_dx][t_dy].first;
        //     dy = coords[t_dx][t_dy].second;

        //     cout << dx << " - " << dy << endl;
        // }

        return abs_differences[rows - 1][cols - 1];
    }
};