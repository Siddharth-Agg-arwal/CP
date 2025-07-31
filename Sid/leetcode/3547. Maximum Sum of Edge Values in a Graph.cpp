class Solution
{
public:
    long long maxScore(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj_list(n);

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        queue<int> nodes;
        for (int i = 0; i < n; i++)
        {
            if (adj_list[i].size() == 1)
                nodes.push(i);
        }

        if (nodes.empty())
            nodes.push(0);
        vector<bool> visited(n, false);
        int assign = 1;
        unordered_map<int, int> node_val;
        while (!nodes.empty())
        {
            int curr = nodes.front();
            nodes.pop();
            if (visited[curr])
                continue;
            visited[curr] = true;

            node_val[curr] = assign;
            // cout << curr << " : " << assign << endl;
            assign += 1;

            for (auto e : adj_list[curr])
            {
                if (!visited[e])
                {
                    nodes.push(e);
                }
            }
        }

        long long max_sum = 0;
        vector<bool> visited2(n, false);
        for (int i = 0; i < n; i++)
        {
            if (visited2[i])
                continue;
            long long curr = node_val[i];
            visited2[i] = true;
            // cout << i << " : " << curr << endl;
            for (auto e : adj_list[i])
            {
                if (!visited2[e])
                {
                    // cout << e << " ";
                    max_sum += curr * node_val[e];
                }
            }
            // cout << endl;
        }

        return max_sum;
    }
};