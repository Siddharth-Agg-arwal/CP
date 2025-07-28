#include <bits/stdc++.h>
using namespace std;

void countPrimes(int n, unordered_map<int, int> &prime_factors)
{
    while (n % 2 == 0)
    {
        prime_factors[2] += 1;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            prime_factors[i] += 1;
            n = n / i;
        }
    }

    if (n > 2)
    {
        prime_factors[n] += 1;
    }
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        unordered_map<int, int> prime_factors;
        for (int i = 0; i < n; i++)
        {
            // cout << nums[i] << " ";
            countPrimes(nums[i], prime_factors);
        }

        bool possible = true;
        for (auto it : prime_factors)
        {
            // cout << it.second << " ";
            if (it.second % n != 0)
            {
                possible = false;
                break;
            }
        }
        if (possible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
