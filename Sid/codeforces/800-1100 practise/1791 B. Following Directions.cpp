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
        string commands;
        cin >> commands;
        bool possible = false;
        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
        {
            if (commands[i] == 'U')
                y += 1;
            else if (commands[i] == 'R')
                x += 1;
            else if (commands[i] == 'L')
                x -= 1;
            else if (commands[i] == 'D')
                y -= 1;

            if (x == 1 && y == 1)
            {
                possible = true;
                cout << "YES\n";
                break;
            }
        }

        if (!possible)
            cout << "NO\n";
    }

    return 0;
}