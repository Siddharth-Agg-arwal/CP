#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        // vector<bool> visited(n+1, false);
        min_heap.push({0, k});
        vector<int> distances(n + 1, 1e9);
        distances[k] = 0;

        while (!min_heap.empty())
        {
            pair<int, int> top = min_heap.top();
            min_heap.pop();
            int top_weight = top.first;
            int top_node = top.second;
            // visited[top_node] = true;

            if (top_weight > distances[top_node])
                continue;

            for (int i = 0; i < times.size(); i++)
            {
                if (times[i][0] == top_node)
                {
                    if (times[i][2] + distances[times[i][0]] < distances[times[i][1]])
                    {
                        distances[times[i][1]] = top_weight + times[i][2];
                        min_heap.push({distances[times[i][1]], times[i][1]});
                    }
                }
            }
        }

        int max_path = 0;
        for (int i = 1; i < distances.size(); i++)
        {
            // cout << distances[i] << " ";
            if (distances[i] == 1e9)
                return -1;
            // min_path += distances[i];
            max_path = max(max_path, distances[i]);
        }

        return max_path;
    }
};