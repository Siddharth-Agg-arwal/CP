#include <bits/stdc++.h>
#include <iostream>
#define IOS()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;

int main()
{
    IOS();
    int n;
    cin >> n;
    if (n > 15)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << 15 - n << endl;
    }

    return 0;
}