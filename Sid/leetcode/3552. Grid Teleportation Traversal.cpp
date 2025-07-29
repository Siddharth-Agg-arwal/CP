class Solution
{
public:
    int minMoves(vector<string> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        if (n == 1 && m == 1)
            return 0;

        vector<vector<int>> distance(n, vector<int>(m, 1e9));
        vector<vector<pair<int, int>>> portals(26);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '.' || matrix[i][j] == '#')
                    continue;
                portals[matrix[i][j] - 'A'].push_back({i, j});
                // cout << i << " " << j << endl;
            }
        }

        // priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> nodes;
        deque<tuple<int, int, int>> nodes;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;

        nodes.emplace_back(0, 0, 0);
        int directions[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int t = 0;
        // int ans = 1e9;
        while (!nodes.empty())
        {
            auto [t, x, y] = nodes.front();
            nodes.pop_front();

            if (dist[x][y] < t)
                continue;
            // visited[x][y] = true;
            char c = matrix[x][y];
            if (c >= 'A' && c <= 'Z')
            {
                auto &list = portals[c - 'A'];
                for (auto [i, j] : list)
                {
                    // if(!visited[i][j]){
                    nodes.emplace_front(t, i, j);
                    // visited[i][j] = true;
                    dist[i][j] = min(dist[i][j], t);
                    // }
                }
                list.clear();
            }
            for (auto direction : directions)
            {
                int dx = direction[0] + x;
                int dy = direction[1] + y;

                if (dx >= 0 && dx < n && dy >= 0 && dy < m && matrix[dx][dy] != '#')
                {
                    if (dist[x][y] + 1 < dist[dx][dy])
                    {
                        dist[dx][dy] = dist[x][y] + 1;
                        nodes.emplace_back(dist[dx][dy], dx, dy);
                    }
                }
            }
            // break;
            // t += 1;
        }

        return (dist[n - 1][m - 1] == 1e9 ? -1 : dist[n - 1][m - 1]);
    }
};