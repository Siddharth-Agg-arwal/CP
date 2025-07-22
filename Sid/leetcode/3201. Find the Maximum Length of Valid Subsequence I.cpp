class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        int num_odds = 0, num_evens = 0, num_odd_eve = 0, num_eve_odd = 0;
        bool odd = true;
        bool even = true;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 1)
            {
                num_odds++;
                if (odd)
                {
                    num_odd_eve++;
                    odd = false;
                }
                if (!even)
                {
                    num_eve_odd++;
                    even = true;
                }
            }
            else if (nums[i] % 2 == 0)
            {
                num_evens += 1;
                if (!odd)
                {
                    num_odd_eve++;
                    odd = true;
                }
                if (even)
                {
                    num_eve_odd++;
                    even = false;
                }
            }
        }

        return max(num_odds, max(num_evens, max(num_odd_eve, num_eve_odd)));
    }
};