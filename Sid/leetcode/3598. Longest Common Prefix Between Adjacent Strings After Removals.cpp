class Solution
{
public:
    int calPrefixLen(string s1, string s2)
    {
        int n = min(s1.size(), s2.size());
        int pref_len = 0;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] == s2[i])
                pref_len++;
            else
                return pref_len;
        }
        return pref_len;
    }

    vector<int> longestCommonPrefix(vector<string> &words)
    {
        int mx1 = 0, mx2 = 0;
        // int mx2 = 0, mx2idx = -1;
        pair<int, int> mx1i = {-1, -1}, mx2i = {-1, -1};

        for (int i = 1; i < words.size() - 1; i++)
        {
            int val1 = calPrefixLen(words[i], words[i - 1]);
            int val2 = calPrefixLen(words[i], words[i + 1]);
            if (val1 > mx1)
            {
                mx2 = mx1;
                mx2i = mx1i;
                mx1 = val1;
                mx1i = {i, i - 1};
            }
            else if (val1 > mx2 && i - 1 != mx1i.first)
            {
                mx2 = val1;
                mx2i = {i, i - 1};
            }

            if (val2 > mx1)
            {
                mx2 = mx1;
                mx2i = mx1i;
                mx1 = val2;
                mx1i = {i, i + 1};
            }
            else if (val2 > mx2 && i + 1 != mx1i.second)
            {
                mx2 = val2;
                mx2i = {i, i + 1};
            }
        }

        vector<int> ans(words.size());
        // cout << mx1 << " " << mx2 << endl;
        // cout << mx1i.first << "- " << mx1i.second << " , " << mx2i.first << "- " << mx2i.second;
        for (int i = 0; i < words.size(); i++)
        {
            if (i != mx1i.first && i != mx1i.second)
            {
                if (i > 0 && i < words.size() - 1)
                {
                    ans[i] = max(calPrefixLen(words[i + 1], words[i - 1]), mx1);
                }
                else
                {
                    ans[i] = mx1;
                }
            }
            else if (i != mx2i.first && i != mx2i.second)
            {
                if (i > 0 && i < words.size() - 1)
                {
                    ans[i] = max(calPrefixLen(words[i + 1], words[i - 1]), mx2);
                }
                else
                {
                    ans[i] = mx2;
                }
                // ans[i] = mx2;
            }
            else
            {
                if (i > 0 && i < words.size() - 1)
                {
                    ans[i] = max(calPrefixLen(words[i + 1], words[i - 1]), min(mx1, mx2));
                }
                else
                {
                    ans[i] = min(mx1, mx2);
                }
            }
        }

        return ans;
    }
};

// [1,1,0,0,2,1,1,1,1,1,1]©leetcode