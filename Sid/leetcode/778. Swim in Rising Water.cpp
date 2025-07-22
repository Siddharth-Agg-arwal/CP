class DSU
{
    vector<vector<int>> rank;
    vector<vector<pair<int, int>>> parent;

public:
    DSU(int n)
    {
        rank.resize(n, vector<int>(n, 0));
        parent.resize(n, vector<pair<int, int>>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                parent[i][j] = {i, j};
            }
        }
    }

    pair<int, int> find(pair<int, int> node)
    {
        if (parent[node.first][node.second] == node)
        {
            return node;
        }

        return parent[node.first][node.second] = find(parent[node.first][node.second]);
    }

    void unionise(pair<int, int> n1, pair<int, int> n2)
    {
        pair<int, int> p1 = find(n1);
        pair<int, int> p2 = find(n2);

        if (p1 == p2)
            return;

        if (rank[p1.first][p1.second] > rank[p2.first][p2.second])
            parent[p2.first][p2.second] = p1;
        else if (rank[p1.first][p1.second] < rank[p2.first][p2.second])
            parent[p1.first][p1.second] = p2;
        else
        {
            parent[p1.first][p1.second] = p2;
            rank[p2.first][p2.second] += 1;
        }

        // cout << p1.first <<  ", " << p1.second << " - " << p2.first << ", " << p2.second << endl;
    }
};

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> elevation_coords;

        int rows = grid.size(), cols = grid.size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                elevation_coords.push({grid[i][j], i, j});
            }
        }

        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // vector<vector<bool>> visited(rows, vector<bool>(rows, false));

        DSU dsu(rows);
        while (!elevation_coords.empty())
        {
            auto [elevation, x, y] = elevation_coords.top();
            elevation_coords.pop();

            // cout << elevation << " : " << x << ", " << y << endl;
            for (auto direction : directions)
            {
                int dx = x + direction[0];
                int dy = y + direction[1];

                if (dx >= 0 && dy >= 0 && dx <= rows - 1 && dy <= cols - 1)
                {
                    if (grid[dx][dy] <= elevation)
                    {
                        // cout << "yo" << endl;
                        dsu.unionise({x, y}, {dx, dy});
                        // visited[dx][dy] = true;
                    }
                    else
                        continue;

                    // cout << grid[x][y] << " : " << grid[dx][dy] << endl;
                }
            }

            if (dsu.find({0, 0}) == dsu.find({rows - 1, cols - 1}))
            {
                return elevation;
            }
        }

        return -1;
    }
};