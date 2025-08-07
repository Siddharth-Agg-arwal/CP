class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max_p = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++)
        {
            if (prices[i] > prices[i - 1])
            {
                max_p += prices[i] - prices[i - 1];
            }
        }

        return max_p;
    }
};