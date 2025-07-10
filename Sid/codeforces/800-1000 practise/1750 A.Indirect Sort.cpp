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
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        bool sorted = true;
        for (int i = 1; i < n; i++)
        {
            if (nums[0] > nums[i])
                sorted = false;
        }

        if (sorted)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}