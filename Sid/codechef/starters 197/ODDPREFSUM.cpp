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
        int odds = 0;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (a % 2 == 1)
                odds++;
        }

        if (odds == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}