#include <bits/stdc++.h>
#include <iostream>
#define IOS()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;
// using long long = ll;

int main()
{
    IOS();
    int tc;
    cin >> tc;
    while (tc--)
    {
        int days, visit_time, jobs;
        cin >> days >> visit_time >> jobs;

        vector<vector<int>> job_times(jobs, vector<int>(2, 0));
        for (int i = 0; i < jobs; i++)
        {
            cin >> job_times[i][0] >> job_times[i][1];
        }

        sort(job_times.begin(), job_times.end());
        int jobs_ongoing = 0;
        int jobs_ended = 0;
        vector<int> jobs_rn(days + 1);
        for (auto &job : job_times)
        {
            for (int k = job[0]; k <= job[1]; k++)
            {
                jobs_rn[k] += 1;
            }
        }

        for (int i = 0; i < jobs_rn.size(); i++)
        {
            cout << jobs_rn[i] << " ";
        }
        cout << endl;

        int mom_start = 1, mom_curr_jobs = jobs_rn[1];
        int bro_start = 1, bro_curr_jobs = jobs_rn[1];
        for (int i = 1; i < days + 1; i++)
        {
            int min_elem = 1e9;
            int max_elem = -1e9;
            for (int j = i; j < i + visit_time && j < days + 1; j++)
            {
                // min_elem = min(min_elem, jobs_rn[j]);
                max_elem = max(max_elem, jobs_rn[j]);
            }
            if (max_elem < mom_curr_jobs)
            {
                mom_start = i;
                mom_curr_jobs = max_elem;
            }

            if (max_elem > bro_curr_jobs)
            {
                bro_start = i;
                bro_curr_jobs = max_elem;
            }
        }

        cout << bro_start << " " << mom_start << endl;
    }

    return 0;
}