#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &adj, int &m, int curr_cats, int parent, int curr_node, const vector<int> &cats)
{
    // if (curr_cats > m)
    //     return 0;

    // if (adj[curr_node].size() == 0 && curr_cats <= m)
    //     return 1;
    if (cats[curr_node] == 1)
    {
        curr_cats += 1;
    }
    else
    {
        curr_cats = 0;
    }

    if (curr_cats > m)
        return 0;

    bool is_leaf = true;
    for (auto neighbor : adj[curr_node])
    {
        if (neighbor != parent)
        {
            is_leaf = false;
            break;
        }
    }

    if (is_leaf)
        return 1;
    int ans = 0;

    for (auto neighbor : adj[curr_node])
    {
        if (neighbor != parent)
        {
            ans += dfs(adj, m, curr_cats, curr_node, neighbor, cats);
        }
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> cats(n, 0);
    for (int i = 0; i < n; i++)
        cin >> cats[i];

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    // if (cats[0] == 1)
    // {
    // for (auto node : adj[0])
    // {
    cout << dfs(adj, m, 0, -1, 0, cats) << endl;
    // }
    // }
    // else
    // {
    //     // for (auto node : adj[0])
    //     // {
    //     cout << dfs(adj, n, m, 0, adj[0][], cats) << endl;
    //     // }
    //     // cout <<
    // }
}