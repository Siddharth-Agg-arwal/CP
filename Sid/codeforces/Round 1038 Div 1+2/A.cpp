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
        int n, m;
        cin >> n >> m;

        if (n == 1 || m == 1)
        {
            cout << "NO\n";
        }
        else if (n <= 2 && m <= 2)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
        }
    }

    return 0;
}