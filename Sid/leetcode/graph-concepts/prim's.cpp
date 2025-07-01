// MST -minimum spanning tree : A tree with N vertices and N-1 edges only which connect all vertices with minimum weight sum over all the edges.
// Prim's -> greedily choose the adjacent node from the pq for the current vertex if its not visited. 

#include <bits/stdc++.h>
using namespace std;

int prims(int num_vertices, vector<vector<pair<int, int>>> &adj, vector<vector<int>> &mst, int src)
{
    vector<bool> visited(num_vertices, false);

    // no need of parent in pq if we do not need the mst and only the weight.
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_heap;
    min_heap.push({0, src, -1});
    int mst_sum = 0;

    while (!min_heap.empty())
    {
        vector<int> top = min_heap.top();
        int top_weight = top[0], top_node = top[1], top_parent = top[2];
        min_heap.pop();

        if (visited[top_node])
            continue;
        visited[top_node] = true;
        mst_sum += top_weight;
        mst.push_back({top_node, top_parent});

        for (auto edge : adj[top_node])
        {
            int weight = edge.first;
            int curr_node = edge.second;
            // int parent_node = edge[2];

            if (!visited[curr_node])
                min_heap.push({weight, curr_node, top_node});
        }
    }

    return mst_sum;
}

int main()
{
    int num_vertices = 3;
    vector<vector<pair<int, int>>> adj = {{{1, 1}, {1, 2}},
                                          {{1, 0}, {3, 2}},
                                          {{3, 1}, {1, 0}}};
    vector<vector<int>> mst;
    int mst_sum = prims(num_vertices, adj, mst, 0);
    cout << "sum of the mst : " << mst_sum << endl;
    for (int i = 0; i < mst.size(); i++)
    {
        cout << mst[i][0] << "," << mst[i][1] << endl;
    }
}