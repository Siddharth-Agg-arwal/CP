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

        vector<string> opinions(n);
        for (int i = 0; i < n; i++)
        {
            cin >> opinions[i];
        }

        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }

        int total_stay = 1;
        for (int i = 1; i < n; i++)
        {
            if (opinions[i] == opinions[0])
            {
                total_stay += 1;
            }
        }

        cout << total_stay << endl;
    }

    return 0;
}