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
        int n, j, k;
        cin >> n >> j >> k;
        vector<int> strengths(n, 0);
        int strongest = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> strengths[i];

            // cout << strengths[i] << " ";
        }

        for (int i = 0; i < n; i++)
        {
            strongest = max(strongest, strengths[i]);
        }

        int max_elim = 0;
        if (strengths[j - 1] == strongest)
        {
            cout << "YES\n";
            continue;
        }
        else
        {
            max_elim = n - 2;
        }
        if (n - max_elim <= k)
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