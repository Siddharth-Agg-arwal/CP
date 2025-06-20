#include <iostream>
using namespace std;
#include <unordered_set>

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_set<char> unique_chars;
        for (int i = 0; i < s.size(); i++)
        {
            unique_chars.insert(s[i]);
        }

        int max_window = 0;
        if (k == 0)
        {
            max_window = 1;
            int curr_window = 1;
            for (int i = 1; i < s.size(); i++)
            {
                if (s[i] == s[i - 1])
                {
                    curr_window += 1;
                }
                else
                {
                    curr_window = 1;
                }

                max_window = max(max_window, curr_window);
            }
            return max_window;
        }

        for (auto ch : unique_chars)
        {
            int curr_window_size = 0, behind_idx = -1, front_idx = 0, temp_k = k, ahead_idx = 0, back_idx = 0;
            // cout << ch << ":-  ";
            for (int i = 0; i < s.size(); i++)
            {
                if (temp_k > 0)
                {
                    if (s[i] != ch)
                    {
                        if (temp_k == k)
                        {
                            if (behind_idx == -1)
                                behind_idx = i;
                            back_idx = i;
                            ahead_idx = i;
                            front_idx = i;
                        }
                        else
                        {
                            if (behind_idx == -1)
                                behind_idx = i;
                            front_idx = i;
                            ahead_idx = i;
                        }
                        temp_k -= 1;
                        curr_window_size += 1;
                    }
                    else
                    {
                        curr_window_size += 1;
                        ahead_idx = i;
                    }
                }
                else
                {
                    if (s[i] == ch)
                    {
                        curr_window_size += 1;
                        ahead_idx = i;
                    }
                    else
                    {
                        behind_idx += 1;
                        while (s[behind_idx] == ch)
                        {
                            // behind_idx/ += 1;
                            behind_idx += 1;
                        }
                        back_idx = behind_idx - 1;
                        while (s[back_idx] == ch)
                        {
                            back_idx -= 1;
                        }
                        // behind_idx = back_idx;
                        ahead_idx = i;
                        front_idx = i;
                        curr_window_size = ahead_idx - back_idx;
                    }
                }

                // cout << behind_idx << "," << front_idx << "      ";
                // cout << curr_window_size << " ";
                max_window = max(curr_window_size, max_window);
            }

            // cout << endl;
        }

        return max_window;
    }
};