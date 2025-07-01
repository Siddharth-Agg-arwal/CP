// sort all the edges according to weight, if the parent(found using DSU) of 2 nodes is not same, add it, else continue

#include <bits/stdc++.h>
using namespace std;

class DisjointSets
{
    vector<int> rank;
    vector<int> parent;

public:
    DisjointSets(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int parent_u = findParent(u);
        int parent_v = findParent(v);

        if (parent_u == parent_v)
            return;
        if (rank[parent_u] < rank[parent_v])
        {
            parent[parent_u] = parent_v;
        }
        else if (rank[parent_u] > rank[parent_v])
        {
            parent[parent_v] = parent_u;
        }
        else
        {
            parent[parent_u] = parent_v;
            rank[parent_v] += 1;
        }
    }
};

static bool comparator(const vector<int> &a, const vector<int> &b)
{
    return a[0] < b[0];
}

int KruskalMSTSum(vector<vector<int>> &edges, int num_vertices, vector<vector<int>> &mst)
{
    DisjointSets dsu(num_vertices);
    int mst_sum = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int weight = edges[i][0];
        int curr_node = edges[i][1];
        int parent_node = edges[i][2];

        int par_curr_node = dsu.findParent(curr_node);
        int par_parent_node = dsu.findParent(parent_node);

        if (par_curr_node == par_parent_node)
            continue;

        else
        {
            dsu.unionByRank(curr_node, parent_node);
            mst_sum += weight;
            mst.push_back({curr_node, parent_node});
        }
    }

    return mst_sum;
}

int main()
{
    int num_vertices = 3;
    vector<vector<pair<int, int>>> edges = {{{2, 1}, {4, 2}},
                                            {{2, 0}, {3, 2}},
                                            {{3, 1}, {3, 0}}};

    // converting to standard form - [weight, node, src]
    vector<vector<int>> edges_std;
    for (int i = 0; i < edges.size(); i++)
    {
        for (int j = 0; j < edges[i].size(); j++)
        {
            edges_std.push_back({edges[i][j].first, edges[i][j].second, i});
        }
    }

    sort(edges_std.begin(), edges_std.end(), comparator);
    vector<vector<int>> mst;
    int mst_sum = KruskalMSTSum(edges_std, num_vertices, mst);
    cout << "MST sum : " << mst_sum << endl;
    for (int i = 0; i < mst.size(); i++)
    {
        cout << mst[i][1] << " -> " << mst[i][0] << endl;
    }

    // for (int i = 0; i < edges_std.size(); i++)
    // {
    //     cout << edges[i][0] << " " << edges[i][1] << " " << edges[i][2] << endl;
    // }
}