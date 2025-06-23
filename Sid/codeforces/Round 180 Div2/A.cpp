#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int a, x, y;
        cin >> a >> x >> y;
        int b = 0;

        if (abs(x - (a + 1)) < abs(x - a) && abs(y - (a + 1)) < abs(y - a))
        {
            cout << "YES\n";
        }
        else if (abs(x - (a - 1)) < abs(x - a) && abs(y - (a - 1) < abs(y - a)))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}