class Solution
{
public:
    static bool comparator(const string &a, const string &b)
    {
        return a.size() < b.size();
    }
    vector<string> removeSubfolders(vector<string> &folder)
    {
        sort(folder.begin(), folder.end(), comparator);
        // for(int i = 0; i < folder.size(); i++) cout << folder[i] << " ";
        vector<string> ans;

        vector<bool> visited(folder.size(), false);
        set<string> parents;

        for (int i = 0; i < folder.size(); i++)
        {
            // if(visited[i]) continue;

            if (folder[i].size() <= 3)
            {
                string parent = folder[i];
                parents.insert(folder[i]);
                ans.push_back(parent);
                continue;
            }

            stringstream ss(folder[i]);
            string str;
            string temp = "";
            bool has_parent = false;
            while (getline(ss, str, '/'))
            {
                if (str == "")
                    continue;
                temp += '/' + str;
                // cout << temp << endl;
                if (parents.find(temp) != parents.end())
                {
                    has_parent = true;
                    break;
                }
            }

            if (!has_parent)
            {
                string parent = folder[i];
                parents.insert(parent);
                ans.push_back(parent);
            }

            // int parentsize = parent.size();
            // visited[i] = true;

            // for(int j = i+1; j < folder.size(); j++){
            //     string curr_folder = folder[j].substr(0, parentsize);
            //     // cout << curr_folder << " ";
            //     // cout << folder[j][parentsize] << " ";
            //     if(curr_folder == parent && folder[j][parentsize] == '/'){
            //         visited[j] = true;
            //     }
            // }
        }
        return ans;
    }
};