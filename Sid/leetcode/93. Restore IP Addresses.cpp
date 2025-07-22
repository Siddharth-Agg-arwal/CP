class Solution
{
public:
    bool validString(string str)
    {
        if (stoi(str) >= 0 && stoi(str) <= 255)
        {
            if (str.size() > 1 && str[0] == '0')
                return false;
            return true;
        }
        return false;
    }

    // void restoreHelper(string& curr, int idx, const string & s, vector<string>& ans, int num_dots, vector<bool> & visited){
    //     if(curr.size() == s.size()){
    //         ans.push_back(curr);
    //         // curr = "";
    //     }
    //     if(num_dots == 0 && idx != s.size()) return;

    //     for(int i = 0; i < s.size(); i++){
    //         if(visited[i]) continue;
    //         string temp = "";
    //         for(int j = 0; j < 3 && i + j < s.size(); j++){
    //             temp += s[i + j];
    //             if(validString(temp)){
    //                 visited[i + j] = true;
    //                 if(curr.size() > 0) curr += '.';
    //                 curr += temp;
    //                 num_dots -= 1;
    //                 restoreHelper(curr, idx + j, s, ans, num_dots, visited);
    //                 num_dots += 1;
    //                 visited[i + j] = false;
    //                 // curr.substr(0, idx);
    //             }
    //         }
    //     }
    // }

    void restoreHelper(string &curr, int idx, const string &s, vector<string> &ans, int parts)
    {
        if (parts == 4 && idx == s.size())
        {
            curr.pop_back();
            ans.push_back(curr);
            curr += '.';
            return;
        }

        if (parts == 4 || idx >= s.size())
        {
            return;
        }

        for (int len = 1; len <= 3 && idx + len <= s.size(); len++)
        {
            string segment = s.substr(idx, len);
            if (validString(segment))
            {
                int og_size = curr.size();
                curr += segment + '.';
                restoreHelper(curr, idx + len, s, ans, parts + 1);
                curr.resize(og_size);
                // parts -= 1;
            }
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ans;
        // int num_dots = 3;
        string curr = "";
        // vector<bool> visited(s.size(), false);
        restoreHelper(curr, 0, s, ans, 0);
        return ans;
    }
};