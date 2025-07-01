#include <bits/stdc++.h>
using namespace std;

int findShortestDistance(vector<vector<int>> &weight_matrix, int src, int num_vertices)
{
    vector<int> distances(num_vertices, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    vector<bool> visited(num_vertices, false);
    visited[0] = true;
    distances[src] = 0;
    min_heap.push({src, 0});

    while (!min_heap.empty())
    {   
        pair<int, int> top_pair = min_heap.top();
        min_heap.pop();

        int curr_node = top_pair.first;
        int curr_cost = top_pair.second;

        if (visited[curr_node])
            continue;

        for (int i = 0; i < num_vertices; i++)
        {
            if (weight_matrix[curr_node][i] != -1)
            {
                if (weight_matrix[curr_node][i] + curr_cost < distances[i])
                {
                    distances[i] = weight_matrix[curr_node][i] + curr_cost;
                    min_heap.push({i, distances[i]});
                }
            }
        }
    }

    return distances[num_vertices - 1];
}

int main()
{
    int num_vertices = 6;
    vector<vector<int>> weights(num_vertices, (vector<int>(num_vertices, -1)));

    // for (int i = 0; i < num_vertices; i++)
    // {
    //     for (int j = 0; j < num_vertices; j++)
    //     {
    //     }
    // }
    vector<vector<int>> weight_matrix = {{-1, 4, 4, -1, -1, -1},
                                         {4, -1, 2, -1, -1, -1},
                                         {4, 2, -1, 3, 1, 6},
                                         {-1, -1, 3, -1, -1, 2},
                                         {-1, -1, 1, -1, -1, 3},
                                         {-1, -1, -1, 2, 3, -1}};

    cout << findShortestDistance(weight_matrix, 0, num_vertices) << endl;
}

// watch striver for theory -
// https://www.youtube.com/watch?v=V6H1qAeB-l4&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=20&t=1080s
