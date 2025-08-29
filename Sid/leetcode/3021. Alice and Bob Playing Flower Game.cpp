class Solution
{
public:
    long long flowerGame(int n, int m)
    {
        long long eves1 = n / 2, odds1 = n - eves1;
        long long eves2 = m / 2, odds2 = m - eves2;

        return (long long)(eves1 * odds2) + (long long)(eves2 * odds1);
    }
};