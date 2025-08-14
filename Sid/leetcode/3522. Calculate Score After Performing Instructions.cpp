class Solution
{
public:
    long long calculateScore(vector<string> &instructions, vector<int> &values)
    {
        long long score = 0;
        // int i = 0;
        int n = values.size();
        vector<bool> visited(n, false);
        for (int i = 0; i < n;)
        {
            if (i > n - 1 || i < 0)
                return score;
            if (visited[i])
                return score;
            if (instructions[i] == "add")
            {
                score += values[i];
                if (i <= n - 1)
                    visited[i] = true;
                i += 1;
                // i += 1;
            }
            else
            {
                if (i <= n - 1)
                    visited[i] = true;
                i += values[i];
                // if(i > n - 1) return score;
            }
        }

        return score;
    }
};
©leetcodes