class Solution
{
public:
    // long long ways = 0;
    long long mod = 1e9 + 7;

    // TLE using dfs
    //  bool dfs(long long n, vector<vector<pair<long long,long long>>> & adj_list, vector<bool> & visited, long long curr_node, long long curr_cost, long long least_cost, long long dst){

    //     if(curr_cost > least_cost){
    //         return false;
    //     }

    //     if(curr_node == dst && curr_cost == least_cost){
    //         return true;
    //     }

    //     visited[curr_node] = true;
    //     for(auto adj : adj_list[curr_node]){
    //         auto[new_node, new_cost] = adj;
    //         if(visited[new_node]) continue;
    //         visited[new_node] = true;
    //         // cout << new_node <<  " " << ways << endl;
    //         bool possible = dfs(n, adj_list, visited, new_node, curr_cost + new_cost, least_cost, dst);
    //         if(possible) ways = (ways%mod + 1)%mod;
    //         visited[new_node] = false;
    //     }
    //     visited[curr_node] = false;

    //     return false;
    // }

    long long shortestPath(long long n, vector<vector<pair<long long, long long>>> &adj_list, vector<long long> &distances)
    {
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> m_heap;
        m_heap.push({0, 0});

        while (!m_heap.empty())
        {
            auto [cost, node] = m_heap.top();
            m_heap.pop();

            for (auto adj : adj_list[node])
            {
                auto [curr_node, curr_cost] = adj;
                if (distances[curr_node] > curr_cost + distances[node])
                {
                    distances[curr_node] = curr_cost + distances[node];
                    m_heap.push({distances[curr_node], curr_node});
                }
            }
        }

        return distances[n - 1];
    }

    int countPaths(int n, vector<vector<int>> &roads)
    {
        const long long INF = LLONG_MAX;
        vector<vector<pair<long long, long long>>> adj_list(n);
        for (long long i = 0; i < roads.size(); i++)
        {
            adj_list[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj_list[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        vector<long long> distances(n, INF);
        distances[0] = 0;
        long long shortest_distance = shortestPath(n, adj_list, distances);

        // vector<bool> visited(n, false);
        // visited[0] = true;
        // long long answer = dfs(n, adj_list, visited, 0, 0, shortest_distance, n - 1);

        vector<long long> ways(n, 0);
        ways[0] = 1;

        vector<pair<long long, int>> order;
        for (int i = 0; i < n; i++)
        {
            order.push_back({distances[i], i});
        }
        sort(order.begin(), order.end());

        for (auto [distance, from] : order)
        {
            for (auto [to, cost] : adj_list[from])
            {
                if (distances[to] == distance + cost)
                {
                    ways[to] = (ways[to] % mod + ways[from] % mod) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};