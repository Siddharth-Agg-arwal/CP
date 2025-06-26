#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bfs()
    {
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        // set<vector<int>> edge_set;
        int n = graph.size();
        if (graph.size() == 0)
            return false;

        vector<bool> c1(n, false);
        vector<bool> c2(n, false);
        queue<int> nodes_to_visit;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!c1[i] && !c2[i])
            {
                nodes_to_visit.push(i);
                visited[i] = true;
                c1[i] = true;

                while (!nodes_to_visit.empty())
                {
                    int curr_node = nodes_to_visit.front();
                    nodes_to_visit.pop();

                    if (graph[curr_node].size() == 0)
                    {
                        c1[curr_node] = true;
                        visited[curr_node] = true;
                        continue;
                    }
                    for (int i = 0; i < graph[curr_node].size(); i++)
                    {
                        if (c1[curr_node])
                        {
                            c2[graph[curr_node][i]] = true;
                            if (c1[graph[curr_node][i]])
                                return false;
                        }
                        else
                        {
                            c1[graph[curr_node][i]] = true;
                            if (c2[graph[curr_node][i]])
                                return false;
                        }

                        if (!visited[graph[curr_node][i]])
                        {
                            nodes_to_visit.push(graph[curr_node][i]);
                            visited[graph[curr_node][i]] = true;
                        }
                    }
                }
            }
        }

        // if(visited_edges < total_edges) return false;

        return true;
    }
};