class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        sort(events.begin(), events.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;

        int book_day = 1;
        int tot_events = 0;
        vector<bool> visited(events.size(), false);
        for (int i = 0; i < events.size() || !min_heap.empty(); i++)
        {
            int j = i;
            while (j < events.size() && events[j][0] == book_day)
            {
                int eve_start = events[j][0];
                int eve_end = events[j][1];
                // visited[j] = true;
                min_heap.push({eve_end, j});
                // cout << eve_start << " " << eve_end << endl;
                j += 1;
            }
            i = j - 1;

            // cout << min_heap.top().second << endl;
            if (min_heap.empty())
            {
                book_day += 1;
                continue;
            }

            // visited[min_heap.top().second] = true;
            min_heap.pop();
            while (!min_heap.empty() && min_heap.top().first <= book_day)
            {
                min_heap.pop();
            }

            book_day += 1;
            tot_events += 1;
        }

        return tot_events;
    }
};