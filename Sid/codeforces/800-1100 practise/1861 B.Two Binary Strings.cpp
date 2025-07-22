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
        string s1, s2;
        cin >> s1 >> s2;
        bool possible = false;
        for (int i = 0; i < s1.size() - 1; i++)
        {
            if (s1[i] == '0' && s1[i + 1] == '1' && s1[i] == s2[i] && s1[i + 1] == s2[i + 1])
            {
                possible = true;
            }
        }

        if (possible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}