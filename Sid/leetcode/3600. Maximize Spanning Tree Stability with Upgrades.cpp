class DSU
{
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionise(int n1, int n2)
    {
        int p1 = findParent(n1);
        int p2 = findParent(n2);
        if (p1 == p2)
            return;
        if (rank[p1] > rank[p2])
            parent[p2] = p1;
        else if (rank[p1] < rank[p2])
            parent[p1] = p2;
        else
        {
            parent[p1] = p2;
            rank[p2]++;
        }
    }
};

class Solution
{
public:
    static bool comparator(const vector<int> &a, const vector<int> &b)
    {
        if (a[3] == b[3])
            return a[2] > b[2];
        else
            return a[3] > b[3];
    }
    int maxStability(int n, vector<vector<int>> &edges, int k)
    {
        int min_must = 1e9;
        DSU dsu(n);
        sort(edges.begin(), edges.end(), comparator);
        int tot_edges = 0;
        priority_queue<pair<int, bool>, vector<pair<int, bool>>, greater<>> to_up;
        for (auto &edge : edges)
        {
            int from = edge[0];
            int to = edge[1];
            int strength = edge[2];
            int must = edge[3];

            int p1 = dsu.findParent(from), p2 = dsu.findParent(to);
            if (must == 1)
            {
                if (p1 == p2)
                    return -1;
                min_must = min(min_must, strength);
                tot_edges += 1;
                dsu.unionise(from, to);
                continue;
            }
            else
            {
                if (p1 == p2)
                    continue;
                to_up.push({strength, false});
                dsu.unionise(from, to);
                tot_edges += 1;
            }
        }

        if (tot_edges != n - 1)
            return -1;
        if (to_up.empty())
            return min_must;
        if (min_must < to_up.top().first)
            return min_must;
        else
        {
            for (int i = 0; i < k && !to_up.empty(); i++)
            {
                auto [val, upgraded] = to_up.top();
                to_up.pop();

                if (upgraded)
                    return min(min_must, val);
                else
                {
                    val = val * 2;
                    upgraded = true;
                    to_up.push({val, upgraded});
                }
            }
        }

        return min(min_must, to_up.top().first);
    }
};