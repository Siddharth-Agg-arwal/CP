#include <bits/stdc++.h>
using namespace std;

// void calcPrimes(int n, unordered_map<int, int> &prime_factors)
// {
//     while (n % 2 == 0)
//     {
//         prime_factors[2] += 1;
//         n = n / 2;
//     }

//     for (int i = 3; i * i <= n; i += 2)
//     {
//         while (n % i == 0)
//         {
//             prime_factors[i] += 1;
//             n = n / i;
//         }
//     }

//     prime_factors[n] += 1;
// }

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        if (n % 2 == 1)
        {
            cout << "Bob\n";
            continue;
        }

        int count = 0;
        while (n % 2 == 0)
        {
            count += 1;
            n = n / 2;
        }

        if (n > 1)
        {
            cout << "Alice\n";
        }
        else if (count % 2 == 0)
        {
            cout << "Alice\n";
        }
        else
        {
            cout << "Bob\n";
        }
        // unordered_map<int, int> prime_factors;
        // calcPrimes(n, prime_factors);
        // int total_odds = 0;
        // for (auto it : prime_factors)
        // {
        //     if (it.first % 2 == 1)
        //     {
        //         total_odds += it.second;
        //     }
        // }

        // if (total_odds % 2 == 0)
        // {
        //     cout << "Bob\n";
        // }
        // else
        // {
        //     cout << "Alice\n";
        // }
    }

    return 0;
}

// Bob
// Alice
// Alice
// Alice
// Bob
// Alice
// Alice
// Alice