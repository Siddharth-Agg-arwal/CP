#include <bits/stdc++.h>
#include <iostream>
#define IOS()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;

long long count_good_up_to(long long n)
{
    if (n == 0)
    {
        return 0;
    }

    const int lcm = 210;
    const int good_in_lcm_block = 48;

    long long num_blocks = n / lcm;
    long long count = num_blocks * good_in_lcm_block;

    long long remainder = n % lcm;
    for (int i = 1; i <= remainder; ++i)
    {
        if (i % 2 != 0 && i % 3 != 0 && i % 5 != 0 && i % 7 != 0)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    IOS();
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long l, r;
        cin >> l >> r;
        long long result = count_good_up_to(r) - count_good_up_to(l - 1);
        cout << result << endl;
    }

    return 0;
}   