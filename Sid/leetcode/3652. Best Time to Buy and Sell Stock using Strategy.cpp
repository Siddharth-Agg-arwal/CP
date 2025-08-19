class Solution
{
public:
    long long maxProfit(vector<int> &prices, vector<int> &strategy, int k)
    {
        long long maxP = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++)
        {
            if (strategy[i] == -1)
            {
                maxP += prices[i] * (-1);
            }
            else if (strategy[i] == 1)
            {
                maxP += prices[i];
            }
        }

        if (k > n)
            return maxP;

        // int mptr1 = (k/2) - 1;
        int mptr = (k / 2);
        long long currProf = maxP;

        // intitial window
        for (int i = 0; i < k; i++)
        {
            if (i < k / 2)
            {
                if (strategy[i] == -1)
                {
                    currProf += prices[i];
                }
                else if (strategy[i] == 1)
                {
                    currProf -= prices[i];
                }
            }
            else if (i >= k / 2)
            {
                if (strategy[i] == 0)
                {
                    currProf += prices[i];
                }
                else if (strategy[i] == -1)
                {
                    currProf += 2 * prices[i];
                }
            }
        }

        maxP = max(maxP, currProf);

        // cout << currProf;
        for (int i = k; i < n; i++)
        {
            if (strategy[i] == -1)
            {
                currProf += 2 * prices[i];
            }
            else if (strategy[i] == 0)
            {
                currProf += prices[i];
            }

            if (strategy[i - k] == -1)
            {
                currProf -= prices[i - k];
            }
            else if (strategy[i - k] == 1)
            {
                currProf += prices[i - k];
            }

            // if(strategy[mptr] == 0 || strategy[mptr] == 1){
            // if(k > 2){
            // if(strategy[mptr] == -1){
            //     currProf -= 2 * prices[mptr];
            // }
            // else{
            currProf -= prices[mptr];
            // }
            mptr += 1;
            // cout << currProf << " ";
            // }

            // }
            // else if(strategy[mptr] == 1){
            //     currProf -= prices[mptr];
            // }
            // else if(strategy[mptr] == -1){
            //     currProf -= prices[mptr];
            // }
            maxP = max(maxP, currProf);
        }

        return maxP;
    }
};