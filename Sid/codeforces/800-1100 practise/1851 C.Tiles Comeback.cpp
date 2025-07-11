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
        long long n, k;
        cin >> n >> k;
        vector<long long> tiles(n);
        unordered_map<long long, long long> freq_tiles;

        for (int i = 0; i < n; i++)
        {
            cin >> tiles[i];
            freq_tiles[tiles[i]] += 1;
        }

        if (freq_tiles[tiles[n - 1]] < k)
        {
            cout << "NO\n";
            continue;
        }

        if (tiles[0] == tiles[n - 1])
        {
            cout << "YES\n";
            continue;
        }

        long long temp = k;
        int last_idx = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (tiles[i] == tiles[n - 1])
                temp--;
            if (temp == 0)
            {
                last_idx = i;
                break;
            }
        }

        temp = k;
        int first_idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (tiles[i] == tiles[0])
                temp--;
            if (temp == 0)
            {
                first_idx = i;
                break;
            }
        }

        if (freq_tiles[tiles[0]] < k)
        {
            cout << "NO\n";
            continue;
        }
        if (first_idx >= last_idx)
        {
            cout << "NO\n";
        }
        else
            cout << "YES\n";
    }

    return 0;
}