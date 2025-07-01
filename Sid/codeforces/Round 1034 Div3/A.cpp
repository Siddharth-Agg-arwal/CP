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
        int n;
        cin >> n;
        if (n % 4 == 0)
        {
            cout << "Bob\n";
        }
        else
        {
            cout << "Alice\n";
        }
    }

    return 0;
}