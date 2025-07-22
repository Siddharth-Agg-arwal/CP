#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<long long> rank;
    vector<long long> cost;
    vector<long long> parent;

    DSU(long long n, vector<long long> &costs)
    {
        rank.resize(n, 0);
        parent.resize(n);
        cost.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            cost[i] = costs[i];
        }
    }

    long long findParent(long long node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(long long u, long long v)
    {
        long long p1 = findParent(u);
        long long p2 = findParent(v);
        if (p1 == p2)
            return;
        if (rank[p1] > rank[p2])
        {
            parent[p2] = p1;
            cost[p1] = min<long long>(cost[p1], cost[p2]);
        }

        else if (rank[p1] < rank[p2])
        {
            parent[p1] = p2;
            cost[p2] = min<long long>(cost[p1], cost[p2]);
        }
        else
        {
            parent[p1] = p2;
            cost[p2] = min<long long>(cost[p1], cost[p2]);
            rank[p2] += 1;
        }
    }
};

int main()
{
    long long n, m;
    cin >> n >> m;

    vector<long long> nums(n);
    long long sum = 0;
    long long cost = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }
    if (m == 0)
    {
        cout << sum << endl;
        return 0;
    }

    DSU dsu(n, nums);
    // vector<vector<int>> adj_list(n + 1);
    for (int i = 0; i < m; i++)
    {
        long long u, v;
        cin >> u >> v;
        dsu.unionByRank(u - 1, v - 1);
        // adj_list[u].push_back(v);
    }

    // long long cost = 0;
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        long long par = dsu.findParent(i - 1);
        if (!visited[par])
        {
            cost += dsu.cost[par];
            visited[par] = true;
        }
    }

    cout << cost << endl;
}