#include <bits/stdc++.h>
#include <iostream>
#define IOS()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;

struct Pair
{
    int u, v, id;
};

int main()
{
    IOS();
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;

        vector<Pair> pairs(n);
        vector<vector<Pair>> adj;
        int max_coord = 0;

        for (int i = 0; i < n; ++i)
        {
            pairs[i].id = i + 1;
            cin >> pairs[i].u >> pairs[i].v;
            if (pairs[i].u > pairs[i].v)
            {
                swap(pairs[i].u, pairs[i].v);
            }
            max_coord = max({max_coord, pairs[i].u, pairs[i].v});
        }

        adj.resize(max_coord + 1);
        for (const auto &p : pairs)
        {
            adj[p.v].push_back(p);
        }

        vector<long long> dp(max_coord + 1, 0);
        vector<pair<int, Pair>> parent(max_coord + 1, {-1, {-1, -1, -1}});

        for (int i = 1; i <= max_coord; ++i)
        {
            dp[i] = dp[i - 1];
            parent[i] = {i - 1, {-1, -1, -1}};

            for (const auto &p : adj[i])
            {
                int j = p.u;
                if (dp[j] + (long long)(i - j) > dp[i])
                {
                    dp[i] = dp[j] + (long long)(i - j);
                    parent[i] = {j, p};
                }
            }
        }

        vector<int> result_indices;
        int current_coord = max_coord;
        while (current_coord > 0)
        {
            pair<int, Pair> pred = parent[current_coord];
            if (pred.second.id != -1)
            {
                result_indices.push_back(pred.second.id);
            }
            current_coord = pred.first;
        }

        reverse(result_indices.begin(), result_indices.end());

        cout << result_indices.size() << endl;
        for (int i = 0; i < result_indices.size(); ++i)
        {
            cout << result_indices[i] << (i == result_indices.size() - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}