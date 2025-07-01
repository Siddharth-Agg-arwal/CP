#include <bits/stdc++.h>
using namespace std;

vector<int> bellman(int num_vertices, vector<vector<int>> &edges, int src)
{
    vector<int> distances(num_vertices, 1e9);
    distances[src] = 0;
    while (--num_vertices)
    {
        for (auto edge : edges)
        {
            bool change = false;
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];

            if (distances[from] + weight < distances[to])
            {
                distances[to] = distances[from] + weight;
                change = true;
            }

            if (!change)
                break;
        }
    }

    return distances;
}

int main()
{
    int num_vertices = 4;
    int src = 0;
    vector<vector<int>>
        edges = {{0, 1, 2},
                 {0, 2, 3},
                 {1, 3, -5},
                 {2, 3, 3},
                 {3, 1, 5}};
    auto x = bellman(num_vertices, edges, src);
    for (auto i : x)
    {
        cout << i << " ";
    }
}