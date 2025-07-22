#include <bits/stdc++.h>
#include <numeric>
#include <iostream>
#define IOS()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;

int main()
{
    IOS();
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long a, b, k;
        cin >> a >> b >> k;

        long long common_divisor = gcd(a, b);
        long long required_k = max(a / common_divisor, b / common_divisor);

        if (k >= required_k)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }

    return 0;
}