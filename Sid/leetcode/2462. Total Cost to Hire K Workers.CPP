class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        long long tot_cost = 0;
        int n = costs.size();
        int l = 0, r = costs.size() - 1;
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>> pq;
        // cout << n << endl;
        for (int i = 0; i < candidates && l <= r; i++)
        {
            pq.push({costs[l], 'l'});
            l += 1;

            if (l <= r)
            {
                pq.push({costs[r], 'r'});
                r -= 1;
            }
        }

        for (int i = 0; i < k; i++)
        {
            auto [cost, idx] = pq.top();
            pq.pop();
            tot_cost += cost;
            if (idx == 'l' && l <= r)
            {
                pq.push({costs[l], 'l'});
                l += 1;
            }
            else if (l <= r)
            {
                pq.push({costs[r], 'r'});
                r -= 1;
            }
        }

        return tot_cost;
    }
};