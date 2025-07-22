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
        string s;
        cin >> s;
        string res = "";
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == 'q')
                res += 'p';
            else if (s[i] == 'p')
                res += 'q';
            else
            {
                res += 'w';
            }
        }

        cout << res << endl;
    }

    return 0;
}