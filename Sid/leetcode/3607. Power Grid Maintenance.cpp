class DSU
{
    vector<int> rank;
    vector<int> parent;

public:
    DSU(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionRank(int node1, int node2)
    {
        int p1 = findParent(node1);
        int p2 = findParent(node2);
        if (p1 == p2)
            return;

        if (rank[p1] > rank[p2])
        {
            parent[p2] = p1;
        }
        else if (rank[p1] < rank[p2])
        {
            parent[p1] = p2;
        }
        else
        {
            parent[p1] = p2;
            rank[p2] += 1;
        }
    }
};

class Solution
{
public:
    vector<int> processQueries(int c, vector<vector<int>> &connections, vector<vector<int>> &queries)
    {
        DSU dsu(c);
        for (int i = 0; i < connections.size(); i++)
        {
            dsu.unionRank(connections[i][0], connections[i][1]);
        }

        // unordered_map<int,vector<int>> parent_stations;
        // unordered_map<int, int> parent_onlineIdx;

        // for(int i = 1; i <= c; i++){
        //     int parent = dsu.findParent(i);
        //     parent_stations[parent].push_back(i);
        // }

        // for(auto it : parent_stations){
        //     sort(it.second.begin(), it.second.end());
        //     parent_onlineIdx[it.first] = 0;
        // }

        vector<vector<int>> compList(c + 1);
        for (int i = 1; i <= c; i++)
            compList[dsu.findParent(i)].push_back(i);

        for (auto &v : compList)
            if (!v.empty())
                sort(v.begin(), v.end());

        vector<int> next_idx(c + 1, 0);
        vector<bool> online(c + 1, true);
        vector<int> ans;
        for (auto query : queries)
        {
            if (query[0] == 2)
            {
                // int parent = dsu.findParent(query[1]);
                // next_idx[parent] += 1;
                online[query[1]] = false;
                continue;
            }
            else
            {
                if (online[query[1]])
                {
                    ans.push_back(query[1]);
                }
                else
                {
                    int parent = dsu.findParent(query[1]);
                    auto &lst = compList[parent];
                    // bool done = false;
                    // int j = next_idx[parent];
                    while (next_idx[parent] < lst.size() && !online[lst[next_idx[parent]]])
                    {
                        next_idx[parent] += 1;
                        // j += 1;
                    }
                    // next_idx[parent] = j;
                    if (next_idx[parent] >= lst.size())
                    {
                        ans.push_back(-1);
                        continue;
                    }
                    int online_station = lst[next_idx[parent]];
                    ans.push_back(online_station);
                    // parent_onlineIdx[parent] += 1;
                }
            }
        }

        return ans;
    }
};

// 1, 2, 2, 1, 1, 1