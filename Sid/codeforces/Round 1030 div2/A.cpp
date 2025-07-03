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
        int n, k;
        cin >> n >> k;

        string ans = "";
        for (int i = 0; i < k; i++)
        {
            ans += '1';
        }
        for (int i = k; i < n; i++)
        {
            ans += '0';
        }

        cout << ans << endl;
    }

    return 0;
}