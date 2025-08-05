class Solution
{
public:
    int countCoveredBuildings(int n, vector<vector<int>> &buildings)
    {
        unordered_map<int, pair<int, int>> x_coords;
        unordered_map<int, pair<int, int>> y_coords;
        const int INF = 1e9;
        int builds = buildings.size();
        for (auto build : buildings)
        {
            int x = build[0];
            int y = build[1];
            if (!x_coords.count(x))
                x_coords[x] = {INF, -INF};
            if (!y_coords.count(y))
                y_coords[y] = {INF, -INF};
            x_coords[x].first = min(x_coords[x].first, y);
            x_coords[x].second = max(x_coords[x].second, y);
            y_coords[y].first = min(y_coords[y].first, x);
            y_coords[y].second = max(y_coords[y].second, x);
            // cout << y << " -> " << x << endl;
        }

        // for(auto &it : x_coords){
        //     sort(it.second.begin(), it.second.end());
        // }
        // for(auto &it : y_coords){
        //     sort(it.second.begin(), it.second.end());
        // }

        int ans = 0;
        for (auto build : buildings)
        {
            int x = build[0], y = build[1];
            if (x == n || y == n || x == 1 || y == 1)
                continue;
            auto x_indices = y_coords[y];
            auto y_indices = x_coords[x];
            // int x_size = x_indices.size();
            // int y_size = y_indices.size();
            bool lower_x = false, lower_y = false, upper_x = false, upper_y = false;
            // if(x_size < 3 || y_size < 3) continue;

            if (x > x_indices.first)
                lower_x = true;
            if (x < x_indices.second)
                upper_x = true;
            if (y > y_indices.first)
                lower_y = true;
            if (y < y_indices.second)
                upper_y = true;

            // cout << x_indices[0] << " " << x_indices[x_size - 1] << " " << y_indices[0] << " " << y_indices[y_size - 1] << endl;
            // for(auto yi : y_indices){
            //     if(yi < y) lower_y= true;
            //     else if(yi > y) upper_y = true;
            //     if(lower_y && upper_y) break;
            // }

            if (lower_x && lower_y && upper_x && upper_y)
            {
                ans++;
            }
        }

        return ans;
    }
};