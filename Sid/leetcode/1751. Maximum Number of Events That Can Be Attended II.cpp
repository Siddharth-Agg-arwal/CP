class Solution
{
public:
    int bs(vector<vector<int>> &events, int currEnd)
    {
        int left = 0;
        int right = events.size();
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (events[mid][0] <= currEnd)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }

    static bool comparator(const vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }

    int maxValue(vector<vector<int>> &events, int k)
    {
        sort(events.begin(), events.end(), comparator);
        int n = events.size();
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

        for (int currIndex = n - 1; currIndex >= 0; currIndex--)
        {
            for (int count = 1; count <= k; count++)
            {
                int nextIndex = bs(events, events[currIndex][1]);
                dp[count][currIndex] = max(dp[count][currIndex + 1], events[currIndex][2] + dp[count - 1][nextIndex]);
            }
        }

        return dp[k][0];
    }
};