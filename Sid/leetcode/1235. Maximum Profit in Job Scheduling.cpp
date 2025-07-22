class Solution
{
public:
    int jobScheduling(vector<int> &S, vector<int> &E, vector<int> &P)
    {
        int n = S.size();
        struct Job
        {
            int s, e, p;
        };
        vector<Job> jobs(n);
        for (int i = 0; i < n; i++)
            jobs[i] = {S[i], E[i], P[i]};
        sort(jobs.begin(), jobs.end(),
             [](auto &a, auto &b)
             { return a.e < b.e; });

        vector<int> ends(n);
        for (int i = 0; i < n; i++)
            ends[i] = jobs[i].e;

        vector<long long> dp(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            auto &job = jobs[i - 1];
            int k = int(upper_bound(ends.begin(), ends.begin() + i - 1,
                                    job.s) -
                        ends.begin()) -
                    1;
            long long include = job.p + (k >= 0 ? dp[k + 1] : 0);
            long long exclude = dp[i - 1];
            dp[i] = max(include, exclude);
        }

        return int(dp[n]);
    }
};
