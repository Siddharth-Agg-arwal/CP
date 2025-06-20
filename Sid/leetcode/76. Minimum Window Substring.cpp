#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {

        vector<priority_queue<int, vector<int>, greater<int>>> char_pos(60);
        unordered_map<char, int> freqT;
        unordered_set<char> charsInT;

        for (int i = 0; i < t.size(); i++)
        {
            freqT[t[i]] += 1;
            charsInT.insert(t[i]);
        }

        int charsT = t.size();
        int lptr = 1e9;
        int rptr = -1;

        for (int i = 0; i < s.size(); i++)
        {
            if (charsT == 0)
                break;
            if (charsInT.find(s[i]) != charsInT.end())
            {
                char_pos[s[i] - 'A'].push(i);
                if (char_pos[s[i] - 'A'].size() > freqT[s[i]])
                {
                    char_pos[s[i] - 'A'].pop();
                }
                else
                {
                    charsT -= 1;
                }
                rptr = max(rptr, i);
            }
        }

        int min_lptr = 1e9;
        for (int i = 0; i < char_pos.size(); i++)
        {
            if (char_pos[i].size())
                min_lptr = min(min_lptr, char_pos[i].top());
        }
        lptr = min_lptr;

        if (charsT != 0)
            return "";
        int min_len = rptr - lptr + 1;
        int m_rptr = rptr;
        int m_lptr = lptr;

        rptr += 1;
        while (rptr < s.size())
        {
            if (charsInT.find(s[rptr]) != charsInT.end())
            {
                char_pos[s[rptr] - 'A'].pop();
                char_pos[s[rptr] - 'A'].push(rptr);
                int min_lptr = 1e9;
                for (int i = 0; i < char_pos.size(); i++)
                {
                    if (char_pos[i].size())
                        min_lptr = min(min_lptr, char_pos[i].top());
                }
                lptr = min_lptr;
            }
            if (rptr - lptr + 1 < min_len)
            {
                min_len = rptr - lptr + 1;
                m_rptr = rptr;
                m_lptr = lptr;
            }
            rptr += 1;
        }

        string ans = "";
        for (int i = m_lptr; i <= m_rptr; i++)
        {
            ans = ans + s[i];
        }

        return ans;
    }
};