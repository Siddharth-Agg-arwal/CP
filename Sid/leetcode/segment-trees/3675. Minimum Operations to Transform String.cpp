class Solution
{
public:
    int minOperations(string s)
    {
        long long min_ops = 0;
        bool t = false;
        // int curr_max = 100;
        // char max_char = '\0';

        vector<int> freq_arr(26, 0);
        for (auto c : s)
        {
            if (c != 'a')
                t = true;
            freq_arr[c - 'a']++;
        }

        if (!t)
            return 0;
        queue<pair<int, char>> q;
        for (int i = 1; i < 26; i++)
        {
            if (freq_arr[i] == 0)
                continue;
            char c = i + 'a';
            q.push({freq_arr[i], c});
            // cout << freq_arr[i] << " " << c << "\n";
        }

        int prev_freq = q.front().first;
        char prev_char = q.front().second;
        q.pop();

        if (q.empty())
        {
            return 'z' - prev_char + 1;
        }

        while (!q.empty())
        {
            pair<int, char> top = q.front();
            q.pop();

            int top_freq = top.first;
            char t_c = top.second;

            int v = t_c - prev_char;
            min_ops += v;
            prev_freq += top_freq;
            prev_char = t_c;
        }

        return ('z' - prev_char + 1) + min_ops;
    }
};