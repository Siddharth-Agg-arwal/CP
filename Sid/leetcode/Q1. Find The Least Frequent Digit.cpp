class Solution
{
public:
    int getLeastFrequentDigit(int n)
    {
        vector<int> nums(10, 0);
        while (n > 0)
        {
            int val = n % 10;
            nums[val]++;
            n /= 10;
        }

        int max_f = INT_MAX;
        int max_n = -1;
        for (int i = 0; i < 10; i++)
        {
            if (nums[i] == 0)
                continue;
            if (nums[i] < max_f)
            {
                max_f = nums[i];
                max_n = i;
            }
        }

        return max_n;
    }
};