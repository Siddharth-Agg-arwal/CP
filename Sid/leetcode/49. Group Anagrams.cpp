#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> str_anagrams;

        for (int i = 0; i < strs.size(); i++)
        {
            string curr_str = strs[i];
            sort(curr_str.begin(), curr_str.end());
            str_anagrams[curr_str].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for (auto it : str_anagrams)
        {
            vector<string> temp;
            for (auto str : it.second)
            {
                temp.push_back(str);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};