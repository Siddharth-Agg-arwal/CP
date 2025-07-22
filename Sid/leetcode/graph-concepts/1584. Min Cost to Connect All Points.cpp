class Solution
{
public:
    class DSU
    {
        vector<int> parent_coords;
        vector<int> rank;

    public:
        DSU(int n)
        {
            parent_coords.resize(n);
            rank.resize(n, 0);

            for (int i = 0; i < n; i++)
                parent_coords[i] = i;
        }

        int findParent(int xy)
        {
            if (parent_coords[xy] == xy)
            {
                return xy;
            }

            return parent_coords[xy] = findParent(parent_coords[xy]);
        }

        void unionByRank(int n1, int n2)
        {
            int p1 = findParent(n1);
            int p2 = findParent(n2);

            if (p1 == p2)
                return;

            if (rank[p1] > rank[p2])
            {
                parent_coords[p2] = p1;
            }
            else if (rank[p1] < rank[p2])
            {
                parent_coords[p1] = p2;
            }
            else
            {
                parent_coords[p1] = p2;
                rank[p2] += 1;
            }
        }
    };

    static bool comparator(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        vector<vector<int>> edges;
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                int node = j;
                int parent = i;
                edges.push_back({dist, node, parent});
            }
        }

        sort(edges.begin(), edges.end(), comparator);

        // debug print
        // for(int i = 0; i < edges.size(); i++){
        //     cout << edges[i][2] << " -> " << edges[i][1] << " - " << edges[i][0] << endl;
        // }

        int mst_sum = 0;
        int mst_nodes = 0;

        DSU dsu(points.size());
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][1];
            int v = edges[i][2];
            int dist = edges[i][0];
            if (mst_nodes == points.size())
                break;
            if (dsu.findParent(u) != dsu.findParent(v))
            {
                dsu.unionByRank(u, v);
                mst_sum += dist;
                mst_nodes += 1;
            }
        }

        return mst_sum;
    }
};