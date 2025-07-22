class Solution
{
public:
    vector<string> partitionString(string s)
    {
        unordered_set<string> segs;
        string curr_str = "";
        vector<string> ans;
        for (int i = 0; i < s.size(); i++)
        {
            curr_str += s[i];
            if (segs.find(curr_str) == segs.end())
            {
                segs.insert(curr_str);
                ans.push_back(curr_str);
                curr_str = "";
            }
        }

        return ans;
    }
};