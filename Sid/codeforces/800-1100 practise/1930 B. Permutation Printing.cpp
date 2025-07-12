#include <bits/stdc++.h>
#include <iostream>
#define IOS()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;

// bool checkPrime(int n)
// {
//     if (n <= 3)
//         return true;

//     if (n % 2 == 0)
//         return false;
//     if (n % 3 == 0)
//         return false;

//     for (int i = 5; i * i <= n; i += 5)
//     {
//         if (n % i == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }

int main()
{
    IOS();
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;

        int i = 1, j = n;
        bool turn = true;
        while (i <= j)
        {
            if (turn)
            {
                cout << j << " ";
                turn = false;
                j -= 1;
            }
            else
            {
                cout << i << " ";
                i += 1;
                turn = true;
            }
        }

        // vector<int> composites;
        // vector<int> primes;

        // for (int i = 1; i <= n; i++)
        // {
        //     bool prime = checkPrime(i);
        //     if (prime)
        //         primes.push_back(i);
        //     else
        //     {
        //         composites.push_back(i);
        //     }
        // }

        // int i = 0, j = 0;
        // bool turn = true;
        // while (i < primes.size() && j < composites.size())
        // {
        //     if (turn)
        //     {
        //         cout << primes[i] << " ";
        //         i += 1;
        //         turn = true;
        //     }
        //     else
        //     {
        //         cout << composites[j] << " ";
        //         j += 1;
        //         turn = false;
        //     }
        // }

        // if (i < primes.size())
        // {
        //     while (i < primes.size())
        //     {
        //         cout << primes[i] << " ";
        //         i += 1;
        //     }
        // }
        // if (j < composites.size())
        // {
        //     while (j < composites.size())
        //     {
        //         cout << composites[j] << " ";
        //         j += 1;
        //     }
        // }
        cout << endl;
    }

    return 0;
}