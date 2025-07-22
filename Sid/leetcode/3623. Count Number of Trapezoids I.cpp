class Solution
{
public:
    static bool comparator(const vector<int> &a, const vector<int> &b)
    {
        return a[1] < b[1];
    }

    int countTrapezoids(vector<vector<int>> &points)
    {
        // vvector<vector<int>> y_sorted = points;
        int mod = 1e9 + 7;
        sort(points.begin(), points.end(), comparator);
        vector<long long> p_lines;
        // sort(points.begin(), points.end());
        int n = points.size();
        if (n < 4)
            return 0;

        for (int i = 0; i < n - 1; i++)
        {
            long long curr = 0;
            int j = i + 1;
            while (j < n && points[i][1] == points[j][1])
            {
                // curr += 1;
                j += 1;
            }
            p_lines.push_back(j - i);
            // cout << j - i  << " ";
            i = j - 1;
        }

        int m = p_lines.size();
        vector<long long> choose2(m);
        for (int i = 0; i < m; i++)
        {
            long long k = p_lines[i];
            choose2[i] = (k >= 2) ? (k * (k - 1) / 2) % mod : 0;
            // cout << choose2[i] << " ";
        }

        long long ans = 0;
        long long prefix = 0;
        for (int i = 0; i < m; i++)
        {
            ans = (ans + (prefix * choose2[i]) % mod) % mod;
            prefix = (prefix + choose2[i]) % mod;
        }

        return (int)ans;
    }
};