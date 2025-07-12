class Solution
{
public:
    static bool comparator(const vector<int> &a, const vector<int> &b)
    {
        return a[1] < b[1];
    }

    long long maxArea(vector<vector<int>> &coords)
    {
        vector<pair<vector<int>, vector<int>>> par_x;
        vector<pair<vector<int>, vector<int>>> par_y;
        vector<vector<int>> y_sorted = coords;
        sort(y_sorted.begin(), y_sorted.end(), comparator);
        sort(coords.begin(), coords.end());

        for (int i = 0; i < coords.size(); i++)
        {
            int j = i + 1;
            while (j < coords.size() && coords[j][0] == coords[i][0])
            {
                par_y.push_back({coords[i], coords[j]});
                j += 1;
            }
        }

        for (int i = 0; i < coords.size(); i++)
        {
            int j = i + 1;
            while (j < y_sorted.size() && y_sorted[j][1] == y_sorted[i][1])
            {
                par_x.push_back({y_sorted[i], y_sorted[j]});
                j += 1;
            }
        }

        vector<int> min_x = coords[0], max_x = coords[coords.size() - 1];
        vector<int> min_y = y_sorted[0], max_y = y_sorted[coords.size() - 1];

        double max_area = -1;
        for (int i = 0; i < par_x.size(); i++)
        {
            double base_len = abs(par_x[i].first[0] - par_x[i].second[0]);
            double a1 = 0, a2 = 0;
            a1 = 0.5 * base_len * abs(min_y[1] - par_x[i].first[1]);
            a2 = 0.5 * base_len * abs(max_y[1] - par_x[i].first[1]);
            max_area = max({max_area, a1, a2});
        }

        // cout << endl;
        for (int i = 0; i < par_y.size(); i++)
        {
            double base_len = abs(par_y[i].first[1] - par_y[i].second[1]);
            double a1 = 0, a2 = 0;
            // if(min_x[1] != par_y[i].first[1]){
            a1 = 0.5 * base_len * abs(min_x[0] - par_y[i].first[0]);
            // }
            // if(max_x[1] != par_y[i].first[1]){
            a2 = 0.5 * base_len * abs(max_x[0] - par_y[i].first[0]);
            // }
            // cout << a1 << " " << a2 << endl;
            // max_area = max(max_area, max(a1, a2));
            // if(a1 > a2 && a1 > max_area){
            //     max_area=  a1;
            // }
            // else if(a2 > a1 &&  a2 > max_area){
            //     max_area = a2;
            // }
            max_area = max({max_area, a1, a2});
        }

        return (max_area == 0 || max_area == -1 ? -1 : 2 * max_area);
    }
};