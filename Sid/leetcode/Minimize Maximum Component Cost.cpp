class DSU
{
    vector<int> parent, rankv;

public:
    DSU(int n) : parent(n), rankv(n, 0)
    {
        iota(parent.begin(), parent.end(), 0);
    }
    int findParent(int x)
    {
        return parent[x] == x ? x : parent[x] = findParent(parent[x]);
    }
    bool unionise(int a, int b)
    {
        a = findParent(a);
        b = findParent(b);
        if (a == b)
            return false;
        if (rankv[a] < rankv[b])
            swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b])
            rankv[a]++;
        return true;
    }
};

class Solution
{
public:
    int minCost(int n, vector<vector<int>> &edges, int k)
    {
        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[2] < b[2]; });
        DSU dsu(n);
        int components = n;
        int result_cost = 0;

        if (components <= k)
        {
            return 0;
        }

        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (dsu.findParent(u) != dsu.findParent(v))
            {
                dsu.unionise(u, v);
                components--;

                result_cost = w;

                if (components == k)
                {
                    break;
                }
            }
        }

        return result_cost;
    }
};
