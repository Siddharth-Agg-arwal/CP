#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // unordered_map<char, int> char_occ;
        // unordered_map<char, int> char_pos;
        vector<int> char_pos(256, -1);
        int end_idx = 0, max_len = 0;

        for (int i = 0; i < s.size(); i++)
        {

            // if(char_pos[s[i]] != -1){
            if (char_pos[s[i]] >= end_idx)
            {
                end_idx = char_pos[s[i]] + 1;
            }
            // }

            char_pos[s[i]] = i;
            max_len = max(i - end_idx + 1, max_len);
        }

        return max_len;
    }
};