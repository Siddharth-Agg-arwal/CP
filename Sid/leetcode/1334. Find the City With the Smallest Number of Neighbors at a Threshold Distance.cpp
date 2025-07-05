class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {

        vector<vector<pair<int, int>>> adj_list(n);
        for (auto edge : edges)
        {
            int from = edge[0], to = edge[1], weight = edge[2];
            adj_list[from].push_back({to, weight});
            adj_list[to].push_back({from, weight});
        }

        int min_cities = 1e9;
        int min_city_connector = -1;
        for (int i = 0; i < n; i++)
        {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            vector<int> distances(n, 1e9);
            pq.push({0, i});
            distances[i] = 0;

            while (!pq.empty())
            {
                auto [cost, from] = pq.top();
                pq.pop();

                if (cost > distanceThreshold)
                    break;

                for (auto adj : adj_list[from])
                {
                    auto [to, cost_to] = adj;
                    if (distances[from] + cost_to > distanceThreshold)
                        continue;
                    if (distances[to] > cost_to + distances[from])
                    {
                        distances[to] = cost_to + distances[from];
                        pq.push({distances[to], to});
                    }
                }
            }

            int curr_cities = 0;
            for (int j = 0; j < distances.size(); j++)
            {
                // cout << distances[j] << " ";
                if (distances[j] > 0 && distances[j] <= distanceThreshold)
                {
                    curr_cities += 1;
                }
            }

            // cout << endl;
            if (curr_cities <= min_cities)
            {
                min_cities = curr_cities;
                min_city_connector = i;
            }
        }

        return min_city_connector;
    }
};