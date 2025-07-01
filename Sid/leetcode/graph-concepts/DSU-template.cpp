class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
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
        return parent[node] = findParent(parent[node]); // path compression - assign the node the value of its parent so no need to find parent again in future iteration.        }
    }

    void unionByRank(int u, int v) // sets the parent to the shorter tree to the root of bigger tree
    {
        int parent_u = find(u);
        int parent_v = find(v);

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

// referece - https://www.youtube.com/watch?v=aBxjDBC4M1U&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=47 - striver dsu