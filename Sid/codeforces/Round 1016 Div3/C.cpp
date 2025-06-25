#include <iostream>
#include <string>
#include <cmath>

#define IOS()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

using namespace std;

long long calc_val(int n, int k)
{
    string s_n = to_string(n);
    string full_s_val = "";

    for (int i = 0; i < k; ++i)
    {
        full_s_val += s_n;
    }

    try
    {
        return stoll(full_s_val);
    }
    catch (const out_of_range &oor)
    {
        return 0; // Returning 0 to indicate overflow or invalid number (as 0 is not prime)
    }
}

bool checkPrime(long long val)
{
    if (val < 2)
    {
        return false;
    }
    if (val == 2 || val == 3)
    {
        return true;
    }
    if (val % 2 == 0 || val % 3 == 0)
    {
        return false;
    }

    for (long long i = 5; i * i <= val; i = i + 6)
    {
        if (val % i == 0 || val % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    IOS();
    int tc;
    cin >> tc;
    while (tc--)
    {
        int x, k;
        cin >> x >> k;

        if (x % 2 == 0 && x != 2)
        {
            cout << "NO" << endl;
            continue;
        }

        long long val = calc_val(x, k);

        if (val == 0)
        { // If calc_val returned 0 due to overflow or if n was 0 initially
            cout << "NO" << endl;
            continue;
        }

        bool ans = checkPrime(val);
        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}