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
        double n, k;
        cin >> n >> k;

        cout << int(ceil((n - 1) / k) + 1) << endl;
    }

    return 0;
}