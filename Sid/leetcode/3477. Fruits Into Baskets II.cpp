class Solution
{
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int n = fruits.size();
        int ans = 0;
        vector<bool> taken(n, false);
        for (int i = 0; i < n; i++)
        {
            // int idx = 0;
            bool given = false;
            for (int j = 0; j < n; j++)
            {
                if (taken[j])
                    continue;
                if (baskets[j] >= fruits[i])
                {
                    // idx = j;
                    taken[j] = true;
                    given = true;
                    break;
                }
            }
            if (!given)
                ans += 1;
        }

        return ans;
    }
};