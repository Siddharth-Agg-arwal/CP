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
        bool possible = true;
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> idx_type(26, -1);
        for (int i = 0; i < n; i++)
        {
            if (idx_type[s[i] - 'a'] != -1)
            {
                if (idx_type[s[i] - 'a'] % 2 != i % 2)
                {
                    possible = false;
                    break;
                }
            }
            else
            {
                idx_type[s[i] - 'a'] = i % 2;
            }
        }

        if (possible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}