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
        int n, m;
        string a, b, st;
        string vlad = "", dima = "";
        cin >> n >> a;
        cin >> m >> b;
        cin >> st;

        int i1 = 0;
        // int i2 = m - 1;
        for (char c : st)
        {
            if (c == 'V')
            {
                vlad = b[i1] + vlad;
                i1++;
            }
            else
            {
                dima = dima + b[i1];
                i1++;
                // i2--;
            }
        }

        cout << vlad + a + dima << endl;
    }

    return 0;
}