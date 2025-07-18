class Solution
{
public:
    bool isPalindrome(string str)
    {
        int lptr = 0, rptr = str.size() - 1;
        while (lptr < rptr)
        {
            if (str[lptr] != str[rptr])
                return false;
            lptr += 1;
            rptr -= 1;
        }
        return true;
    }

    void partitionHelper(vector<string> &temp, int partitions_size, vector<vector<string>> &ans, string &s, int idx)
    {
        if (partitions_size == s.size())
        {
            ans.push_back(temp);
            return;
        }

        for (int len = 1; len <= s.size() - partitions_size; len++)
        {
            string curr_partition = s.substr(idx, len);
            if (isPalindrome(curr_partition))
            {
                // cout << curr_partition << endl;
                partitions_size += curr_partition.size();
                temp.push_back(curr_partition);
                partitionHelper(temp, partitions_size, ans, s, idx + len);
                partitions_size -= temp.back().size();
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> temp = {};
        partitionHelper(temp, 0, ans, s, 0);
        return ans;
    }
};