class Solution
{
public:
    long long solve(const vector<int> &s1, const vector<int> &d1, const vector<int> &s2, const vector<int> &d2)
    {
        int n1 = s1.size();
        int n2 = s2.size();

        vector<pair<int, int>> r2(n2);
        for (int i = 0; i < n2; ++i)
        {
            r2[i] = {s2[i], d2[i]};
        }
        sort(r2.begin(), r2.end());

        vector<long long> min_f_suf(n2 + 1, LLONG_MAX);
        for (int i = n2 - 1; i >= 0; --i)
        {
            min_f_suf[i] = min(min_f_suf[i + 1], (long long)r2[i].first + r2[i].second);
        }

        vector<int> min_d_pre(n2);
        min_d_pre[0] = r2[0].second;
        for (int i = 1; i < n2; ++i)
        {
            min_d_pre[i] = min(min_d_pre[i - 1], r2[i].second);
        }

        long long res = LLONG_MAX;

        for (int i = 0; i < n1; ++i)
        {
            long long f1 = (long long)s1[i] + d1[i];

            auto it = upper_bound(r2.begin(), r2.end(), make_pair((int)f1, INT_MAX));
            int k = distance(r2.begin(), it);

            if (k < n2)
            {
                res = min(res, min_f_suf[k]);
            }

            if (k > 0)
            {
                long long min_d = min_d_pre[k - 1];
                res = min(res, f1 + min_d);
            }
        }
        return res;
    }

    int earliestFinishTime(vector<int> &ls, vector<int> &ld, vector<int> &ws, vector<int> &wd)
    {
        long long res1 = solve(ls, ld, ws, wd);
        long long res2 = solve(ws, wd, ls, ld);
        return min(res1, res2);
    }
};