class Solution
{
public:
    long long maxSpending(vector<vector<int>> &values)
    {
        priority_queue<int, vector<int>, greater<>> pq;
        for (int i = 0; i < values.size(); i++)
        {
            for (int j = 0; j < values[0].size(); j++)
            {
                pq.push(values[i][j]);
            }
        }

        long long d = 1, ans = 0;
        while (!pq.empty())
        {
            ans += pq.top() * d;
            d += 1;
            pq.pop();
        }

        return ans;
    }
};