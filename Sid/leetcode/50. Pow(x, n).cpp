class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1;
        if (x == 1)
            return 1;
        if (x == -1 && n % 2 == 0)
            return 1;
        if (x == -1 && n % 2 == 1)
            return -1;

        long long N = n;
        if (n < 0)
        {
            x = 1 / x;
            N = -N;
        }

        while (N > 0)
        {
            if (N % 2 == 1)
            {
                ans *= x;
            }
            x *= x;
            N /= 2;
        }

        return ans;
    }
};