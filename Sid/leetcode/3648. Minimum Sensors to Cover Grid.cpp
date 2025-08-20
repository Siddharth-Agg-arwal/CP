class Solution
{
public:
    int minSensors(int n, int m, int k)
    {
        double range = 2 * k + 1;
        // double range_sq = range * range;
        if (range >= m && range >= n)
            return 1;
        return (ceil((double)(n / range)) * ceil((double)(m / range)));
    }
};