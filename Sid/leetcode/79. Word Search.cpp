#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool dfs(int i, int j, string word, vector<vector<char>> &board, vector<vector<bool>> &visited, int word_len)
    {

        if (i < 0 || j < 0 || i > board.size() - 1 || j > board[0].size() - 1 || visited[i][j])
        {
            return false;
        }
        word_len += 1;

        char curr_char = board[i][j];
        // cout << curr_char << " ";

        if (word[word_len - 1] != curr_char)
        {
            word_len -= 1;
            // visited[i][j] = false;
            return false;
        }

        if (word_len == word.size())
        {
            return true;
        }

        // cout << i << "," << j << endl;
        visited[i][j] = true;
        bool found = dfs(i + 1, j, word, board, visited, word_len) ||
                     dfs(i - 1, j, word, board, visited, word_len) ||
                     dfs(i, j + 1, word, board, visited, word_len) ||
                     dfs(i, j - 1, word, board, visited, word_len);
        visited[i][j] = false;

        return found;
    }

    bool exist(vector<vector<char>> &board, string word)
    {

        vector<int> freq_arr(60, 0);
        vector<int> freq_board(60, 0);
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                freq_board[board[i][j] - 'A'] += 1;
            }
        }
        // cout << "test" << " ";

        for (int i = 0; i < word.size(); i++)
        {
            freq_arr[word[i] - 'A'] += 1;
        }
        // cout << "test" << " ";

        for (char c : word)
        {
            int idx = c - 'A';
            if (freq_board[idx] < freq_arr[idx])
                return false;
        }
        // cout << "test" << " ";

        if (freq_board[word[0] - 'A'] < freq_board[word[word.size() - 1] - 'A'])
        {
            reverse(word.begin(), word.end());
        }
        // cout << "test" << " ";

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                    int word_len = 0;
                    bool ans = dfs(i, j, word, board, visited, word_len);
                    if (ans)
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};