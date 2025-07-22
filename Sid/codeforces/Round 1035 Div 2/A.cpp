#include <bits/stdc++.h>
#include <iostream>
#define IOS()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;

int main()
{
    IOS();
    long long tc;
    cin >> tc;
    while (tc--)
    {
        long long a, b, x, y;
        cin >> a >> b >> x >> y;

        if (a == b)
        {
            cout << 0 << endl;
            continue;
        }

        if (a > b && b == a - 1 && a % 2 == 1)
        {
            cout << y << endl;
            continue;
        }

        // if (b == 0 && a == 1)
        // {
        //     cout << y << endl;
        //     continue;
        // }

        if (a > b && b != a - 1)
        {
            cout << -1 << endl;
            continue;
        }

        // if (b == 0 && a != 1)
        // {
        //     cout << -1 << endl;
        //     continue;
        // }

        if (a > b)
        {
            cout << -1 << endl;
            continue;
        }

        long long total_ops = b - a;
        long long add_ops = 0, xor_ops = 0;
        if (y < x && b % 2 == 0 && a % 2 == 0)
        {
            add_ops = (b - a) / 2;
            xor_ops = (b - a) / 2;
        }
        else if (y < x && b % 2 == 0 && a % 2 == 1)
        {
            add_ops = ((b - a) / 2) + 1;
            xor_ops = ((b - a) / 2);
        }
        else if (y < x && b % 2 == 1 && a % 2 == 1)
        {
            add_ops = (b - a) / 2;
            xor_ops = (b - a) / 2;
        }
        else if (y < x && b % 2 == 1 && a % 2 == 0)
        {
            add_ops = (b - a) / 2;
            xor_ops = ((b - a) / 2) + 1;
        }
        else
        {
            add_ops = total_ops;
        }
        cout << (add_ops * x) + (xor_ops * y) << endl;
    }

    return 0;
}