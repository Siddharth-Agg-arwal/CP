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
        if (n % 2 == 0)
        {
            cout << -1 << endl;
            continue;
        }
        vector<int> ans;
        for (int i = 1; i <= n; i += 2)
        {
            ans.push_back(i);
        }
        for (int i = 2; i <= n; i += 2)
        {
            ans.push_back(i);
        }

        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }

        cout << endl;
    }

    return 0;
}