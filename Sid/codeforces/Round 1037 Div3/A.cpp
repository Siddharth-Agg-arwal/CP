#include <bits/stdc++.h>
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
        int x;
        cin >> x;

        int val = 1e9;
        while (x > 0)
        {
            val = min(val, x % 10);
            x = x / 10;
        }

        cout << val << endl;
    }

    return 0;
}