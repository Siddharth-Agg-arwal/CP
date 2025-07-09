class Solution
{
public:
    int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime)
    {
        int n = startTime.size();
        vector<int> event_dur(n, 0);
        int init_window = 0, max_free = max(startTime[0] - 0, eventTime - endTime[n - 1]);
        for (int i = 0; i < n; i++)
        {
            event_dur[i] = endTime[i] - startTime[i];
        }
        for (int j = 0; j < k && j < n; j++)
        {
            init_window += event_dur[j];
        }

        int curr_window = init_window;
        for (int i = 0; i < n; i++)
        {

            if (i < k - 1)
                continue;

            if (i >= k)
            {
                curr_window += event_dur[i];
                curr_window -= event_dur[i - k];
            }

            int curr_free = 0;
            int st = (i == k - 1 ? 0 : endTime[i - k]);
            int et = (i < n - 1 ? startTime[i + 1] : eventTime);
            // if(i == k) curr_window = init_window;

            int start_align = st + curr_window;
            curr_free = et - start_align;
            int end_align = et - curr_window;
            curr_free = max(curr_free, end_align - st);
            max_free = max(curr_free, max_free);
            // temp += 1;
            // if(i - k >= 0) curr_window = curr_window - event_dur[i - k];
            // cout << st << " -> " << et << " - " << start_align << " : " << end_align <<endl;
        }

        return max_free;
    }
};