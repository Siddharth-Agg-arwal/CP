#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

// Adjacency list to represent the tree
vector<int> adj[200005];
// Vector to store the resulting directed edges
vector<pair<int, int>> directed_edges;
// Vector to store the children of each node in the rooted tree
vector<int> children[200005];
// Parent array for the rooted tree
int parent[200005];
int n;

// DFS to build a rooted tree structure (parent and children)
void build_rooted_tree(int u, int p)
{
    parent[u] = p;
    children[u].clear();
    for (int v : adj[u])
    {
        if (v != p)
        {
            children[u].push_back(v);
            build_rooted_tree(v, u);
        }
    }
}

// The main DFS function to orient edges
vector<int> solve_dfs(int u)
{
    // Start with a list of unmatched nodes containing only the current vertex u
    vector<int> unmatched_nodes = {u};

    // Process all children of u
    for (int v : children[u])
    {
        // Get the list of unmatched nodes from the child's subtree
        vector<int> unmatched_from_child = solve_dfs(v);

        // To optimize, always merge the smaller list into the larger one
        if (unmatched_from_child.size() > unmatched_nodes.size())
        {
            swap(unmatched_from_child, unmatched_nodes);
        }

        // Pair up unmatched nodes from the current list and the child's list
        for (int node_from_child : unmatched_from_child)
        {
            int node_from_main_list = unmatched_nodes.back();
            unmatched_nodes.pop_back();
            directed_edges.push_back({node_from_child, node_from_main_list});
        }
    }
    // Return the final list of unmatched nodes for the subtree at u
    return unmatched_nodes;
}

void solve()
{
    cin >> n;
    // Clear data structures for the new test case
    for (int i = 1; i <= n; ++i)
    {
        adj[i].clear();
    }
    directed_edges.clear();

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n == 2)
    {
        cout << "NO" << endl;
        return;
    }

    // Root the tree at vertex 1
    build_rooted_tree(1, 0);

    // Get the final list of unmatched nodes after processing the whole tree
    vector<int> remaining_unmatched = solve_dfs(1);

    // The last node in the list is the root of the final unmatched chain
    int chain_root = remaining_unmatched.back();
    remaining_unmatched.pop_back();

    // Connect the remaining unmatched nodes in a chain towards the root's parent
    for (int node : remaining_unmatched)
    {
        directed_edges.push_back({node, parent[chain_root]});
        chain_root = node;
    }

    // Output the result
    cout << "YES" << endl;
    for (const auto &edge : directed_edges)
    {
        cout << edge.first << " " << edge.second << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}