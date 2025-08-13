class Solution
{
public:
    long long maxTotal(vector<int> &value, vector<int> &limit)
    {
        int n = value.size();
        map<int, priority_queue<int>> lim_pq;
        for (int i = 0; i < n; i++)
        {
            lim_pq[limit[i]].push(value[i]);
        }

        priority_queue<int, vector<int>, greater<>> min_h;
        long long tot_val = 0;
        int curr_active = 0;

        for (auto &it : lim_pq)
        {
            while (!it.second.empty() && it.first > curr_active)
            {
                int top = it.second.top();
                it.second.pop();
                tot_val += top;
                min_h.push(it.first);
                curr_active += 1;

                if (lim_pq.find(curr_active) != lim_pq.end())
                {
                    lim_pq[curr_active] = {};
                }

                int temp = curr_active;
                while (!min_h.empty() && min_h.top() <= curr_active)
                {
                    min_h.pop();
                    temp -= 1;
                }
                curr_active = temp;
            }
        }

        return tot_val;
    }
};