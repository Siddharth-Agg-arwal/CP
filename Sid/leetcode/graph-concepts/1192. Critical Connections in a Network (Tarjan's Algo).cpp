class Solution
{
public:
    int timer = 1;

    void dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &adj_list, vector<vector<int>> &bridges, int time_in[], int low_time[])
    {
        vis[node] = 1;
        time_in[node] = low_time[node] = timer;
        timer += 1;
        for (auto &it : adj_list[node])
        {
            if (it == parent)
            {
                continue;
            }

            if (vis[it] == 0)
            {
                dfs(it, node, vis, adj_list, bridges, time_in, low_time);
                low_time[node] = min(low_time[node], low_time[it]);
                if (low_time[it] > time_in[node])
                {
                    bridges.push_back({it, node});
                }
            }
            else
            {
                low_time[node] = min(low_time[node], low_time[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj_list(n);
        for (auto &connection : connections)
        {
            adj_list[connection[0]].push_back(connection[1]);
            adj_list[connection[1]].push_back(connection[0]);
        }

        vector<int> vis(n, 0);
        int time_in[n];
        int low_time[n];
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj_list, bridges, time_in, low_time);
        return bridges;
    }
};