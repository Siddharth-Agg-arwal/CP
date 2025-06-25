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
        string n_str;
        cin >> n_str;

        vector<int> zeroes(n_str.size(), 0);
        for (int i = 1; i < n_str.size(); i++)
        {
            if (n_str[i - 1] == '0')
            {
                zeroes[i] = zeroes[i - 1] + 1;
            }
            else
                zeroes[i] = zeroes[i - 1];
            // cout << zeroes[i] << " ";
        }
        // cout << endl;

        int idx = 0;
        // cout << n_str.size() << " ";
        for (int i = n_str.size() - 1; i >= 0; i--)
        {
            if (n_str[i] != '0')
            {
                idx = i;
                break;
            }
        }

        if (idx != 0)
        {
            int val = n_str.size() - zeroes[idx] - 1;
            // cout << zeroes[idx] << " ";
            cout << val << endl;
        }
        else
        {
            cout << n_str.size() - 1 << endl;
        }
    }

    return 0;
}