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
        long long p;
        cin >> p;

        long long max_sum = 0;
        long long min_val = 27;
        vector<int> freq_arr(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            freq_arr[s[i] - 'a'] += 1;
            max_sum += (s[i] - 'a' + 1);
            if ((s[i] - 'a') < min_val)
                min_val = s[i] - 'a';
        }

        if (p >= max_sum)
        {
            cout << s << endl;
            continue;
        }

        if (p < min_val)
        {
            cout << "" << endl;
            continue;
        }

        while (p < max_sum)
        {
            for (int i = 25; i >= 0; i--)
            {
                if (freq_arr[i] == 0)
                    continue;
                while (freq_arr[i] > 0 && max_sum > p)
                {
                    max_sum -= (i + 1);
                    freq_arr[i] -= 1;
                }

                if (p >= max_sum)
                    break;
            }
        }

        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (freq_arr[s[i] - 'a'] > 0)
            {
                ans += s[i];
                freq_arr[s[i] - 'a'] -= 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}