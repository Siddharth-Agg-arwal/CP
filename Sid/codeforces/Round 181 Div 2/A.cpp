
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
        vector<bool> visited(s.size(), false);
        string res = "";
        vector<int> freq_arr(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            freq_arr[s[i] - 'A'] += 1;
        }

        while (freq_arr[19] != 0)
        {
            res += 'T';
            freq_arr[19] -= 1;
        }

        for (int i = 0; i < 26; i++)
        {
            if (freq_arr[i] == 0)
                continue;
            else
            {
                while (freq_arr[i] > 0)
                {
                    res += i + 'A';
                    freq_arr[i] -= 1;
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}