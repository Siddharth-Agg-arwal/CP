class DSU
{

    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int node1, int node2)
    {
        int parent_node1 = findParent(node1);
        int parent_node2 = findParent(node2);

        if (parent_node1 == parent_node2)
            return;

        if (rank[parent_node1] > rank[parent_node2])
        {
            parent[parent_node2] = parent_node1;
        }
        else if (rank[parent_node1] < rank[parent_node2])
        {
            parent[parent_node1] = parent_node2;
        }
        else
        {
            parent[parent_node1] = parent_node2;
            rank[parent_node2] += 1;
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<int, vector<string>> uid_accName;
        priority_queue<pair<string, int>, vector<pair<string, int>>, greater<>> pq;
        int id = 0;
        for (auto acc : accounts)
        {
            uid_accName[id].push_back(acc[0]);
            for (int i = 1; i < acc.size(); i++)
            {
                pq.push({acc[i], id});
            }
            id += 1;
        }
        priority_queue<pair<string, int>, vector<pair<string, int>>, greater<>> temp;
        temp = pq;

        DSU dsu(uid_accName.size());
        string prev_acc = "";
        int prev_id = -1;
        while (!temp.empty())
        {
            auto [email, id] = temp.top();
            temp.pop();

            if (prev_acc == "")
            {
                prev_acc = email;
                prev_id = id;
                continue;
            }

            if (prev_acc == email)
            {
                dsu.unionByRank(prev_id, id);
            }

            prev_id = id;
            prev_acc = email;
        }

        prev_acc = "";
        prev_id = -1;

        while (!pq.empty())
        {

            auto [email, id] = pq.top();
            pq.pop();
            if (prev_acc == email)
            {
                continue;
            }
            prev_id = id;
            prev_acc = email;

            int parent = dsu.findParent(id);
            uid_accName[parent].push_back(email);
        }

        vector<vector<string>> ans;
        // int j = 0;
        for (auto it : uid_accName)
        {
            int arr_size = it.second.size();
            if (arr_size == 1)
                continue;

            vector<string> temp2;
            for (int k = 0; k < arr_size; k++)
            {
                temp2.push_back(it.second[k]);
            }
            ans.push_back(temp2);
        }

        return ans;
    }
};