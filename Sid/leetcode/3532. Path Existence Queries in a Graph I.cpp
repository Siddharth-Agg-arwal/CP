class DSU
{
    vector<int> rank;
    vector<int> parent;

public:
    DSU(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node)
    {
        if (parent[node] == node)
            return parent[node];
        return parent[node] = findParent(parent[node]);
    }

    void unionise(int n1, int n2)
    {
        int p1 = findParent(n1);
        int p2 = findParent(n2);
        if (p1 == p2)
            return;
        if (rank[p1] < rank[p2])
            parent[p1] = p2;
        else if (rank[p2] < rank[p1])
            parent[p2] = p1;
        else
        {
            parent[p2] = p1;
            rank[p1]++;
        }
        return;
    }
};

class Solution
{
public:
    vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
    {
        DSU dsu(n);
        for (int i = 1; i < n; i++)
        {
            // for(int j = i; j < n; j++){
            if (abs(nums[i] - nums[i - 1]) <= maxDiff)
            {
                dsu.unionise(i, i - 1);
            }
            // }
        }

        vector<bool> ans;
        ans.reserve(queries.size());
        for (auto q : queries)
        {
            int to = q[0], from = q[1];
            int p1 = dsu.findParent(to), p2 = dsu.findParent(from);
            if (p1 == p2)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }

        return ans;
    }
};